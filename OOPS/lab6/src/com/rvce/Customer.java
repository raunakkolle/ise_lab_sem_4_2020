package com.rvce;
import java.util.Scanner;
public class Customer
{
	public static void main(String[] args)
	{
		Account ob=new Account();
		Scanner sc=new Scanner(System.in);
		System.out.println("Enter the amount to deposit and whether the currency is OLD or NEW");
		int amt=sc.nextInt();
		String ctype=sc.next();
		ob.deposit(amt, ctype);
		ob.curbal();
		System.out.println("Enter the amount to withdraw");
		amt=sc.nextInt();
		ob.withdraw(amt);
		ob.curbal();
	}
}
