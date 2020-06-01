package com.rvce;

public class Snake implements tiredAnimal {
    @Override
    public void eat() {
        System.out.println("GULP GULP");
    }

    @Override
    public void sound() {
        System.out.println("HISS HISS");
    }

    @Override
    public void status() {
        System.out.println("hiss hiss");
    }
}
