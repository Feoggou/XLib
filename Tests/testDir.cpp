/*
*  Copyright 2015 Samuel Ghineț
*  
*  Licensed under the Apache License, Version 2.0 (the "License");
*  you may not use this file except in compliance with the License.
*  You may obtain a copy of the License at
*  
*      http://www.apache.org/licenses/LICENSE-2.0
*  
*  Unless required by applicable law or agreed to in writing, software
*  distributed under the License is distributed on an "AS IS" BASIS,
*  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
*  See the License for the specific language governing permissions and
*  limitations under the License.
*/

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "XLib/XLib.h"
#include "XLib/Dir.h"

using namespace Zen;

TEST(EmptyDir, CreateDir)
{
	Dir dir;
    std::tstring name(T("temp"));

	ASSERT_FALSE(Dir::Exists(name));
	ASSERT_NO_THROW(dir = Dir::Create(name));
	ASSERT_STREQ(name.data(), dir.FullPath().data());
	ASSERT_TRUE(dir.Exists());
	ASSERT_TRUE(Dir::Exists(name));
	ASSERT_TRUE(dir.Remove());
	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, CreateDirUnicodeName)
{
    Dir dir;
    std::tstring name(T("temp-şperţ-p"));
    //size_t sz = name.length();

    ASSERT_FALSE(Dir::Exists(name));
    ASSERT_NO_THROW(dir = Dir::Create(name));
    ASSERT_STREQ(name.data(), dir.FullPath().data());
    ASSERT_TRUE(dir.Exists());
    ASSERT_TRUE(Dir::Exists(name));
    ASSERT_TRUE(dir.Remove());
    ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, CreateDirTwice)
{
    Dir dir(T("temp2"));

	ASSERT_FALSE(dir.Exists());
	ASSERT_TRUE(dir.Create());
	ASSERT_TRUE(dir.Exists());
	ASSERT_FALSE(dir.Create());
	ASSERT_TRUE(dir.Remove());
	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, RemoveDirTwice)
{
    Dir dir(T("temp3"));

	ASSERT_FALSE(dir.Exists());
	ASSERT_TRUE(dir.Create());
	ASSERT_TRUE(dir.Exists());
	ASSERT_TRUE(dir.Remove());
	ASSERT_FALSE(dir.Exists());
	ASSERT_FALSE(dir.Remove());
	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, GetCurrentDir)
{
	Dir dir = Dir::GetCurrent();
	ASSERT_GT(dir.FullPath().size(), 1UL);
}

//TODO: FixEmptyDir, CreateDir of invalid path

int main(int argc, char* argv[])
{
	::testing::InitGoogleMock(&argc, argv);
	
	return RUN_ALL_TESTS();
}
