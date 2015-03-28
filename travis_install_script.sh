#!/bin/bash

echo "user=$USER"
gcc --version
g++ --version

set -ev

function have_exe_version {
have_tool=0

tool_name=$1
expected_major_v=$2
expected_minor_v=$3
expected_build_v=$4

x=`which $tool_name`
if [ "$x" ]
then
	have_tool=1
	i=0
	for x in `cmake --version | grep -o --regexp "[0-9]*"`
	do
#		echo "ver$i=$x"

		vers[$i]=$x
		i=$(($i+1))
	done

	major_v=${vers[0]}
	minor_v=${vers[1]}
	build_v=${vers[2]}

	if [ $major_v -lt $expected_major_v ]; then echo "$tool_name: expected major version $expected_major_v. have: major_v"; have_tool=0; fi
	if [ $minor_v -lt $expected_minor_v ]; then echo "$tool_name: expected minor version $expected_minor_v. have: minor_v"; have_tool=0; fi
	if [ $build_v -lt $expected_build_v ]; then echo "$tool_name: expected build version $expected_build_v. have: build_v"; have_tool=0; fi
fi
	echo $have_tool
}

#cmake

have_tool=`have_exe_version cmake 3 1 3`

if [ $have_tool -eq 0 ]
then
	wget http://www.cmake.org/files/v3.1/cmake-3.1.3.tar.gz
	tar -zxf cmake-3.1.3.tar.gz
	export CXX=g++
	cd cmake-3.1.3
	./bootstrap && make && sudo make install
else
	echo "have cmake of good version!"
fi

cmake --version

have_tool=`have_exe_version g++ 4 8 0`

if [ $have_tool -eq 0 ]
then
	sudo apt-get install g++-4.8
else
	echo "have g++ of good version!"
fi

# gmock
wget https://googlemock.googlecode.com/files/gmock-1.7.0.zip
unzip gmock-1.7.0.zip
