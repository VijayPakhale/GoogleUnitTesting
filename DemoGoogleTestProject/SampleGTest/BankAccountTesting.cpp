#include "pch.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include "../BankAccount/bank_account.h"

namespace BankAccountTesting
{
	TEST(AccountTesting, DefaultBalance)
	{
		Account acc;
		ASSERT_EQ(acc.GetBalance(), 0);
	}

	TEST(AccountTesting, CheckDepositeBalance)
	{
		Account acc{1200.15};
		ASSERT_EQ(acc.GetBalance(), 1200.15);
	}

	TEST(AccountTesting, CheckWithdrawBalance)
	{
		Account acc{ 1200.15 };
		acc.Withdraw(200);

		double epsilon = 0.00001;
		auto diff = std::abs(acc.GetBalance() - 1000.15);
		ASSERT_LE(diff, epsilon);
	}
	
	TEST(AccountTesting, CheckWrongWithdrawalException)
	{
		Account acc{ 1200.15 };
		ASSERT_THROW(acc.Withdraw(50000), std::runtime_error);
	}

	TEST(AccountTesting, CheckBalanceTransfer)
	{
		Account from{ 1200 };
		Account to{ 500 };

		from.Transfer(200, to);
		ASSERT_EQ(to.GetBalance(), 700);
	}
}
