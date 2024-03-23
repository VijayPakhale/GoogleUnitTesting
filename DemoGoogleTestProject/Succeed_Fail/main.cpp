#include <gtest/gtest.h>

#define __WIN32__

namespace OperatingSystem
{

	TEST(WindowsSuite, DummyTest1)
	{
	#ifdef __WIN32__
			SUCCEED();
	#else
			FAIL();
	#endif // __WIN32__
	}

	TEST(LinuxSuite, DummyTest)
	{
	#ifdef __WIN32__
			SUCCEED();
	#else
			FAIL();
	#endif // __WIN32__
	}
}
int main(int argc, char* argv[])
{
	#ifdef  __WIN32__
	testing::GTEST_FLAG(filter) = "WindowsSuite.*";
	#else
	testing::GTEST_FLAG(filter) = "LinuxSuite.*";
	#endif //  __WIN32__

	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}