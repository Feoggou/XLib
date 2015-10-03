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

#include "zLib/zLib.h"
#include "zLib/Dir.h"
#include "zLib/Path.h"

#include <string>

#include <chrono>

using namespace Zen;

std::tstring createUniqueName(const std::tstring& base = T("uniqueName_"))
{
	std::tstring uniqueName = base;

	auto now = std::chrono::steady_clock::now();
	auto rep = now.time_since_epoch().count();
	std::wstring ws;

	uniqueName += ZEN_TO_TSTRING(rep);

	return uniqueName;
}

TEST(DefaultDir, DoesNotExist)
{
	Dir dir;

	ASSERT_FALSE(dir.Exists());
}

TEST(DefaultDirWithPath, DoesNotExist)
{
	Dir dir(createUniqueName());

	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, CreateDir)
{
	Dir dir(createUniqueName());

	ASSERT_TRUE(dir.Create());
}

TEST(EmptyDir, CreatedDirExists)
{
	Dir dir(createUniqueName());

	dir.Create();
	ASSERT_TRUE(dir.Exists());
}

TEST(EmptyDir, RemoveDir)
{
	Dir dir(createUniqueName());
	dir.Create();

	ASSERT_TRUE(dir.Remove());
}

TEST(EmptyDir, RemovedDirDoesNotExist)
{
	Dir dir(createUniqueName());
	dir.Create();
	dir.Remove();

	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, CreateDirUnicodeName)
{
    std::tstring name = createUniqueName(T("temp-şperţ-p"));
    
	ASSERT_NO_THROW(Dir::Create(name));
}

// NOTE: if we can create a directory with a unique name, we can clearly perform other file system operations with paths containing special characters.
TEST(EmptyDir, CreatedDir_SpecialChars_Exists)
{
	std::tstring name = createUniqueName(T("temp-şperţ-p"));

	Dir dir = Dir::Create(name);
	ASSERT_TRUE(dir.Exists());
}

TEST(DISABLED_EmptyDir, CreateDir_InvalidPath)
{
	FAIL();
}

TEST(EmptyDir, CreateDirTwice_ReturnsFalse)
{
	Dir dir(createUniqueName());

	dir.Create();
	ASSERT_FALSE(dir.Create());
}

TEST(EmptyDir, RemoveDirTwice_ReturnsFalse)
{
	Dir dir(createUniqueName());

	dir.Create();
	dir.Remove();
	ASSERT_FALSE(dir.Remove());
}

TEST(CurrentDir, Exists)
{
	Dir dir = Dir::GetCurrent();
	ASSERT_TRUE(dir.Exists());
}

TEST(DirPath, DisplayName_WhenPathIsName)
{
	std::tstring name = createUniqueName();
	Dir dir(name);

	ASSERT_EQ(dir.Name(), name);
}

TEST(DISABLED_DirPath, DisplayName_WhenPathIsRelative)
{
	std::tstring path = T("a/b/c/");
	std::tstring name = createUniqueName();
	path += name;

	Dir dir(path);

	ASSERT_EQ(dir.Name(), name);
}

TEST(DirPath, Absolute)
{
	std::tstring name = createUniqueName();
	Dir dir(name);
	std::tstring fullPath = dir.FullPath();

	ASSERT_GT(fullPath.length(), name.length());
}

TEST(DirPath, CurrentDirPath_isAbsolute)
{
	Dir current = Dir::GetCurrent();

	std::tstring fullName = current.FullPath();

    ASSERT_TRUE(Path::isAbsolute(fullName));
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleMock(&argc, argv);
	
	return RUN_ALL_TESTS();
}
