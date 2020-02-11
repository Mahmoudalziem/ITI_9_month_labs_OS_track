/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package calcstack;

import java.util.Stack;
import jdk.nashorn.internal.runtime.JSType;

/**
 *
 * @author Taha CompuTech
 */
public class CalcStack {

    public static void main(String[] args) {

        Stack<Integer> sVal = new Stack<Integer>();
        Stack<String> sOp = new Stack<String>();
        int result = 0;
        for (int i = 0; i < args.length; i++) {
            if (isNumber(args[i])) {
                sVal.push(Integer.parseInt(args[i]));
            } else {
                if (sOp.isEmpty()) {
                    sOp.push(args[i]);
                } else {
                    if (isHigher(args[i], sOp.peek())) {
                        sOp.push(args[i]);
                    } else {
                        int x = sVal.pop();
                        String op = sOp.pop();
                        int y = sVal.pop();

                        sVal.push(calculate(y, op, x));

                        sOp.push(args[i]);
                    }
                }
            }

        }
        while (!sOp.isEmpty()) {
            int x = sVal.pop();
            String op = sOp.pop();
            int y = sVal.pop();

            result = sVal.push(calculate(y, op, x));
        }
        System.out.println(result);

    }

    static boolean isNumber(String num) {
        try {
            Integer.parseInt(num);

        } catch (NumberFormatException e) {

            return false;
        }

        return true;
    }

    static boolean isHigher(String op1, String op2) {
        switch (op1) {
            case "+":
            case "-":
                return false;

            case "*":
            case "/": {
                if (op2.equals("+") || op2.equals("-")) {
                    return true;
                } else {
                    return false;
                }
            }
        }
        return false;
    }

    static int calculate(int x, String op, int y) {
        int res = 0;
        switch (op) {
            case "+":
                res = x + y;
                break;
            case "-":
                res = x - y;
                break;
            case "*":
                res = x * y;
                break;
            case "/":
                res = x / y;
                break;
        }
        return res;
    }

}
