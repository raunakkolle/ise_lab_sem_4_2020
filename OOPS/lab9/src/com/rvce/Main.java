package com.rvce;

import java.lang.reflect.Array;
import java.util.ArrayList;

public class Main {

    public static void main(String[] args) {
	// write your code here

        ArrayList<String> array = new ArrayList<String>();

        array.add("BLOOD RED");
        array.add("BRIGHT GREEN");
        array.add("SKY BLUE");
        array.add("DARK WHITE");
        array.add("BRIGHT BLACK");


        // ARRAYLIST TO ARRAY
        String ss[] = new String[array.size()];
        ss =  array.toArray(ss);

        for (int i = 0; i < ss.length; i++) {
            System.out.println(ss[i]);
        }

        System.out.println("reverse arraylist");
        int size = array.size();
//        array.add(array.get(0));
        for (int i = 1; i < size; i++) {
            String d = array.get(i);
            array.remove(i);
            array.add(0,d);

        }
        for (String s:array
             ) {
            System.out.println(s);
        }

        System.out.println("sublist");
        for (String s: array.subList(1,3)
             ) {
            System.out.println(s);
        }
        System.out.println("clone");

        ArrayList<String > array2 = (ArrayList<String>) array.clone();

        for (String s: array2
        ) {
            System.out.println(s);
        }

    }
}
