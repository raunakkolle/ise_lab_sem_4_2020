package com.rvce;
public class DemonitisationException extends Exception
{
	void display(int amt)
	{
		System.out.println("Deposit of old currency of Rs"+amt+" crosses Rs5000 and cannot be deposited ");
	}
}
