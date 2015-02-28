#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "XLib/Dir.h"

using namespace Zen;

TEST(EmptyDir, CreateDir)
{
	Dir dir;
	std::wstring name(L"temp");

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
	Dir dir(L"temp2");

	ASSERT_FALSE(dir.Exists());
	ASSERT_TRUE(dir.Create());
	ASSERT_TRUE(dir.Exists());
	ASSERT_FALSE(dir.Create());
	ASSERT_TRUE(dir.Remove());
	ASSERT_FALSE(dir.Exists());
}

TEST(EmptyDir, RemoveDirTwice)
{
	Dir dir(L"temp3");

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
