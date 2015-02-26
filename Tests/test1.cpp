#include "gmock/gmock.h"
#include "XLib/XLib.h"

TEST(FactorialTest, HandlesZeroInput) {
	EXPECT_EQ(1, 1);
}

int main(int argc, char* argv[])
{
	::testing::InitGoogleMock(&argc, argv);
	
	return RUN_ALL_TESTS();
}
