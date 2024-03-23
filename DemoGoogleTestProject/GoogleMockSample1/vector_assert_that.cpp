#include <vector>
#include <gtest/gtest.h>
#include <gmock/gmock.h>
using namespace std;

vector<int> GenerateNum(int n, int limit)
{
	vector<int> result; 
	result.reserve(n);
	for (auto i = 0; i < n; ++i)
	{
		result.push_back(i % limit);
	}

	return result;
}

TEST(AssertThatTest, VectorTest)
{
	std::vector<int> result = GenerateNum(5, 3);

	ASSERT_THAT(result, testing::ElementsAre(0, 1, 2, 0, 1));
}

TEST(AssertThatTest, VectorRangeTest)
{
	using namespace testing;
	std::vector<int> result = GenerateNum(5, 3);

	ASSERT_THAT(result, testing::Each(AllOf(Ge(0), Lt(3))));
	//AllOf, AnyOf, Gt, Le, Lt, Eq
}

