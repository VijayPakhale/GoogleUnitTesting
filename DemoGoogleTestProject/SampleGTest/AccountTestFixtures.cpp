#include "pch.h"
#include <gtest/gtest.h>
#include <stdexcept>
#include "../BankAccount/bank_account.h"
using namespace std;

namespace TestFixturesOfAccount
{
	class AccountTestFixtures : public testing::Test
	{
	protected:
		Account* account;

	public:
		AccountTestFixtures();
		virtual ~AccountTestFixtures();
		void SetUp() override;
		void TearDown() override;
		static void SetUpTestSuite();
		static void TearDownTestSuite();
	};

	AccountTestFixtures::AccountTestFixtures()
	{
		cout << "AccountTestFixtures Constructor" << endl;
	}

	AccountTestFixtures::~AccountTestFixtures()
	{
		cout << "AccountTestFixtures Destructor" << endl;
	}

	void AccountTestFixtures::SetUp()
	{
		cout << "SetUp" << endl;
		account = new Account;
	}

	void AccountTestFixtures::TearDown()
	{
		cout << "TearDown" << endl;
		delete account;
	}

	void AccountTestFixtures::SetUpTestSuite()
	{
		cout << "SetUpTestSuite" << endl;
	}

	void AccountTestFixtures::TearDownTestSuite()
	{
		cout << "TearDownTestSuite" << endl;
	}

	TEST_F(AccountTestFixtures, ZeroBalanceTest)
	{
		ASSERT_EQ(account->GetBalance(), 0);
	}

	TEST_F(AccountTestFixtures, TestDeposite)
	{
		double bal = account->GetBalance();
		account->Deposite(1200);
		ASSERT_EQ(account->GetBalance(), bal + 1200);
	}

	TEST_F(AccountTestFixtures, FullBalanceWithdrawalTest)
	{
		account->Deposite(1400);
		account->Withdraw(1400);
		ASSERT_EQ(account->GetBalance(), 0.00);
	}
}

/*
Important:
If Setup and TearDown is there why we need Constructor and Destructor. or Vice-versa.

Answer:
There are few things which cannot be done inside SetUp.
ex.:- if you have const ref data member use constructor.
If you want to call virtual functions used SetUp.
if you want to use ASSERT use SetUp.
if you want to throw exception after test run, use TearDown instead destructor.
*/

/*
- A fixture is useful for removing code duplication.
- It's used where the setup phase and cleanup phase are similar.
- It's a class where the test setup is written in the SetUp() method and the cleanup is in TearDown().
- A new fixture is created for each test.
*/