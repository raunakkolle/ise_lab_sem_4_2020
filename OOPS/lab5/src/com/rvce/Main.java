package com.rvce;

public class Main {

    public static void main(String[] args) {
	// write your code here
        Lion L = new Lion();
        Snake S = new Snake();

        L.eat();
        L.sound();

        S.eat();
        S.sound();
        S.status();

    }
}
