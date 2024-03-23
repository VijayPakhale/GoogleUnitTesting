#include "pch.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include "../BankAccount/bank_account.h"
using namespace std;

//Parameterized test cases are required when you want to test a 
// functionality with multiple types of paramter.
namespace parameterized_test
{
	class RangeValidator
	{
		int low, high;
	public:
		RangeValidator(int low, int high) : low{ low }, high{ high }
		{

		}

		bool Validate(int value)
		{
			return value >= low && value <= high;
		}
	};

	class ValidateFixture : public testing::TestWithParam<int>
	{
	public:
		RangeValidator rangeValidator{ 4,9 };
	};

	TEST_P(ValidateFixture, CheckInRange)
	{
		int param = GetParam();

		bool isWithinRange = rangeValidator.Validate(param);
		ASSERT_TRUE(isWithinRange);
	}
	INSTANTIATE_TEST_CASE_P(CheckInRange, ValidateFixture, testing::Values(5, 4, 7, 6));


	class ValidateNegativeFixture : public testing::TestWithParam<int>
	{
	public:
		RangeValidator rangeValidator{ 4,9 };
	};

	TEST_P(ValidateNegativeFixture, CheckNotInRange)
	{
		int param = GetParam();

		bool isWithinRange = rangeValidator.Validate(param);
		ASSERT_FALSE(isWithinRange);
	}
	INSTANTIATE_TEST_CASE_P(CheckNotInRange, ValidateNegativeFixture, testing::Values(-5, -4, 70, 16));

	//Alternate way to do it is using value,expected value set.
	class ValidatePairFixture : public testing::TestWithParam<std::pair<int, bool>>
	{
	public:
		RangeValidator rangeValidator{ 4,9 };
	};

	TEST_P(ValidatePairFixture, CheckIntCases)
	{
		std::pair<int, bool> pairElement = GetParam();
		int param = std::get<0>(pairElement);
		int expectedOutput = std::get<1>(pairElement);

		bool isWithinRange = rangeValidator.Validate(param);
		ASSERT_EQ(isWithinRange, expectedOutput);
	}
	INSTANTIATE_TEST_CASE_P(CheckIntCases, ValidatePairFixture, 
				testing::Values(std::make_pair(-4, false), 
								std::make_pair(4, true)));

}
/*
- Parameterized tests can be used to generate tests that have the same body, but different input values.
- When you generate a test, the expected output values can be packed together with the input values using complex data structures.
- Generators can be used to generate input values for the test.
- SetUpTestCase() and TearDownTestCase() are methods that can be overriden.
- Generators:-
	- Range: Range(begin, end, [,step])
	- Values: Values(x1, x2, x3, x4,..)
	- ValuesIn: ValuesIn(Container& iterator)
	- Bool: True&False
	- Combine: Combine(gen1, gen2...) this generates cartesain product.
*/
