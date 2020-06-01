package com.rvce;

public class Lion implements animal {


    @Override
    public void eat() {
        System.out.println("CHEW CWEW");
    }

    @Override
    public void sound() {
        System.out.println("ROAR ROAR");
    }
}
