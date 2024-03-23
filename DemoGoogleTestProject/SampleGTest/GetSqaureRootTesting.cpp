#include "pch.h"
#include "../StaticLibSqrt/mysqrt.h"

namespace GetSqureRootTesting
{
	TEST(TestName, TestCaseName) {
		EXPECT_EQ(1, 1);
		EXPECT_TRUE(true);
	}

	TEST(CheckSquareRoot, SqrtOf100)
	{
		ASSERT_EQ(10, GetSquareRoot(100));
	}

	TEST(ExceptionTests, CheckAnyException)
	{
		ASSERT_ANY_THROW(GetSquareRoot(-8));
	}

	TEST(ExceptionTests, CheckRuntimeException)
	{
		//using namespace std;
		ASSERT_THROW(GetSquareRoot(-8), std::runtime_error);
	}

	TEST(ExceptionTests, CheckNoException)
	{
		//using namespace std;
		ASSERT_NO_THROW(GetSquareRoot(8));
	}
}


/*
EXPECT_EQ
EXPECT_TRUE
ASSERT_EQ
*/