#pragma once
class Account
{
	double balance;

public:
	Account(double init = 0);
	void Deposite(double amount);
	void Withdraw(double amount);
	double GetBalance() const;
	void Transfer(double amount, Account& to);
};

