#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "XLib/XLib.h"
#include "XLib/Dir.h"

using namespace Zen;

class FxtEmptyDir : public ::testing::Test
{
public:
	FxtEmptyDir() : m_path(L"temp_path") {}

	void TearDown() override
	{
		Zen::Dir::Remove(L"temp");
		ASSERT_FALSE(Zen::Dir::Exists(L"temp"));
	}

protected:
	std::wstring m_path;
};

TEST_F(FxtEmptyDir, CreateDir)
{
	Zen::Dir dir;
	std::wstring name(L"temp");

	ASSERT_NO_THROW(dir = Zen::Dir::Create(name));
	ASSERT_STREQ(name.data(), dir.Name().data());

	ASSERT_TRUE(dir.Exists());
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleMock(&argc, argv);
	
	return RUN_ALL_TESTS();
}
