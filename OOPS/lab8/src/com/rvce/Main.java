package com.rvce;

import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here

        lambda isEven = (n)-> n%2==0;

        lambda isPrime = (n) -> {
            for (int i = 2 ; i<n; i++){
                if(n%i==0){return false;}
            }

            return true;
        };

        lambda palindrome = (n) ->{
            ArrayList<Integer> arr = new ArrayList<Integer>();
            while(n!=0){
                arr.add(n%10);
                n/=10;
            }
//            System.out.println("ARR"+arr);
            for (int i = 0; i < arr.size(); i++) {
                if(arr.get(i) != arr.get(arr.size()-1-i)){return  false;}

            }
            return true;
        };

//        isEven.func(2);
        System.out.println(isEven.func(2)); //True
        System.out.println(isEven.func(3)); //False
        System.out.println(isPrime.func(29)); //True
        System.out.println(isPrime.func(25)); //False
        System.out.println(palindrome.func(12321)); //True
        System.out.println(palindrome.func(1231)); //False
    }
}

interface lambda {
    boolean func (int n);
}