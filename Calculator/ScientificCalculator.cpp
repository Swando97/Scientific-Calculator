//
//  ScientificCalculator.cpp
//  Calculator
//
//  Created by Adam Swanson on 2020-07-30.
//  Copyright © 2020 Adam Swanson. All rights reserved.
//

#include <stdio.h>
#include <iostream>
#include <cmath>
#include <stdexcept>
#include "Calculator.h"
using namespace std;

class ScientificCalculator : public Calculator {
public:
// ------------------------------------------------- Constructor --------------------------------------------------
        ScientificCalculator(){
            // Bounds-Checking Logic Explained:
            //      1) If initial input is VALID (i.e. = 1,2,3,4,5,6) displayMenu()
            //      2) Otherwise display ERROR MESSAGE from Customozed Exception Class
            try{
                displayMenu(); // Private class method to display "Scientific Calculator" menu
            }
            catch(OutOfRange r) {
                cout << r.what() << endl; // Display "customized exception" message
                itr = 0.0; // Used to Re-show "Main Menu"
            }
            catch(WrongType w){
                cout << w.what() << endl;
                exit(0);
            }
        }
// ------------------------------------------------- Destructor ---------------------------------------------------
        ~ScientificCalculator(){}
// ------------------------------------------------- Templates ----------------------------------------------------
        template <class type> type sine(type num1) {
             type result = sin(num1);
             return result;
           }
        template <class type> type cosine(type num1) {
          type result = cos(num1);
          return result;
        }
        template <class type> type tangent(type num1) {
          type result = tan(num1);
          return result;
        }
        template <class type> type power(type num1,type num2){
            type result = pow(num1, num2);
            return result;
        }
        template <class type> type logarithm(type num1){
            type result = log10(num1);
            return result;
        }
// ----------------------------------------------- Calculate Method -----------------------------------------------
    void calculate(){
        while (flag){
            if(itr == 1.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::add(getNum1(),getNum2());
                cout << "The sum of " << getNum1() << " (+) " << getNum2() << " = " << answer << endl << endl;
                // Error Handling
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 2.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::subtract(getNum1(), getNum2());
                cout << "The difference of " << getNum1() << " (-) " << getNum2() << " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 3.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::multiply(getNum1(), getNum2());
                cout << "The product of " << getNum1() << " (×) " << getNum2() << " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 4.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::division(getNum1(), getNum2());
                cout << "The quotient of " << getNum1() << " (÷) " << getNum2() << " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 5.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::squareRoot(getNum1());
                cout << "The root of " << getNum1() << " (√) " <<  " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 6.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = Calculator::square(getNum1());
                cout << "The square of " << getNum1() << " (x²) " <<  " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 7.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = sine(getNum1());
                cout << "The root of " << getNum1() << " (√) " <<  " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 8.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = cosine(getNum1());
                cout << "The square of " << getNum1() << " (x²) " <<  " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 9.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = tangent(getNum1());
                cout << "The root of " << getNum1() << " (√) " <<  " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 10.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = power(getNum1(),getNum2());
                cout << "The answer of " << getNum1() << "^" << getNum2() << " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 11.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
                answer = logarithm(getNum1());
                cout << "The answer of log(" << getNum1() << ")"  << " = " << answer << endl << endl;
                try{
                    itr = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    itr = 0.0;
                }catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0);
                }
            }
            else if(itr == 0.0){
                flag = false;
            }
        }
    }
private:
    float itr = 0.0;
    float answer = 0.0;
    bool flag = true;
    // --------------------------------------------- Private Methods ----------------------------------------------
    // Display the "Basic Calculator Menu"
       float displayMenu(){
           cout << "---------- SCIENTIFIC CALCULATOR ----------" << endl;
           cout << "Press 1: Add (+) \nPress 2: Subtract (-) \nPress 3: Multiply (×) \nPress 4: Divide (÷) \nPress 5: Square Root (√)\nPress 6: Square (x²) \nPress 7: Sine (sin(x)) \nPress 8: Cosine (cos(x)) \nPress 9: Tangent (tan(x)) \nPress 10: Exponent (xⁿ)\nPress 11: Logarithm (log(x)) \n[Press 0:] Alternative Mode \nOption: ";
           if(cin >> itr){
               if(itr==1.0||itr==2.0||itr==3.0||itr==4.0||itr==5.0||itr==6.0||itr==7.0||itr==8.0||itr==9.0||itr==10.0||itr==11.0||itr==0.0){
                   ; //do nothing
               }
               else{
                   OutOfRange r;
                   throw r;
               }
           }
           else{
               WrongType w;
               throw w;
           }
           cout << endl;
           return itr;
       }
    
};

