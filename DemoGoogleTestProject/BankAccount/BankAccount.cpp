// BankAccount.cpp : Defines the functions for the static library.
//

#include "pch.h"
#include "framework.h"
#include <stdexcept>
#include "bank_account.h"

Account::Account(double init) : balance{ init }
{

}

void Account::Deposite(double amount)
{
	this->balance += amount;
}

void Account::Withdraw(double amount)
{
	if (balance < amount)
		throw std::runtime_error("Low balance");
	balance -= amount;
}

double Account::GetBalance() const
{
	return balance;
}

void Account::Transfer(double amount, Account& to)
{
	this->Withdraw(amount);
	to.Deposite(amount);
}
