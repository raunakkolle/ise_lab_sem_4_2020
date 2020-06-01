package com.rvce;
public class Account
{
	int bal;
	Account()
	{
		bal=500;
	}
	void deposit(int amt,String ctype)
	{
		try
		{
			if(amt>5000 && ctype.equals("OLD"))
				throw new DemonitisationException();
			else
			{
				bal+=amt;
				System.out.println("Amount deposited ");
			}
		}
		catch(DemonitisationException e)
		{
			e.display(amt);
		}
	}
	
	void curbal()
	{
		System.out.println("Current Balance is Rs"+bal);
	}
	
	void withdraw(int amt)
	{
		if(bal-amt<500)
		{
			System.out.println("Balance too low to withdraw Rs"+amt);
		}
		else
		{
			bal-=amt;
			System.out.println("Amount withdrawed");
		}
	}
}
