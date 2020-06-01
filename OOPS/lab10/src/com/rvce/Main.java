package com.rvce;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws InterruptedException
    {

        String S = "Java vs Python, Java is Java & Python is Python";
        String[] s = S.split(" ");
        System.out.println(s[s.length -2]);

        S = S.replace("Java","C++");
        S = S.replace("Python","Java");
        S = S.replace("C++","Python");

        System.out.println(S);

        for (int i = 0; i < s.length; i++) {
            System.out.println(s[i]);
        }


    }
}