//  Calculator.h
//
//  Superclass "Calculator.h" is used to define all the operations that a calculator can perform... these functions are created as generic so all datatypes can be passed to it. Templates are about the compiler generating code at compile-time instead of run-time!
//
//  Operations include:
//      1) Addition
//      2) Subtraction
//      3) Multiplication
//      4) Division
//      5) Sqaure Root
//      6) Square
//      7) setNum1()
//      8) getNum1()
//      9) setNum2()
//     10) getNum2()
//
//  *** NOTE: Custom Exception Class ***
//  Custom Exception Class "OutOfRange" is created/defined @ highest level of the hierarchy b/c of inheritance needs, they subclasses will inherit class PROPERTIES and BEHAVIORS- including the ERROR MESSAGE defined at the "base" class or the highest level of hierarchy.
//
//  Created by Adam Swanson on 2020-07-30.
//  Copyright © 2020 Adam Swanson. All rights reserved.
//
#ifndef Calculator_h
#define Calculator_h

#include <cmath>
#include <stdio.h>
#include <iostream>
using namespace std;

// Customized Exception Class
class OutOfRange : public exception{
public :
const char* what(){
    return "\n*********** ERROR MESSAGE **********\n  Out-Of-Range... Please Try Again \n************************************\n";
}
};
class WrongType : public exception{
public :
const char* what(){
    return "\n*********** FATAL ERROR MESSAGE **********\n  Wrong Data Type... Restart Application \n********************************************\n";
}
};
// Base class "Calculator" - top of hierarchy
class Calculator {
public:
    // -------------------- TEMPLATE METHODS --------------------
    template <class type> type add(type num1, type num2) {
      type result = num1 + num2;
      return result;
    }
    template <class type> type subtract(type num1, type num2){
      type result = num1 - num2;
      return result;
    }
    template <class type> type multiply(type num1, type num2){
        type result = num1 * num2;
        return result;
    }
    template <class type> type division(type num1, type num2){
        type result = num1 / num2;
        return result;
    }
    template <class type> type squareRoot(type num1){
        type result = sqrt(num1);
        return result;
    }
    template <class type> type square(type num1){
        type result = pow(num1, 2);
        return result;
    }
    // -------------------- GETTER/SETTER METHODS --------------------
    void setNum1(float num){
        num1 = num;
    }
    float getNum1(){
        return num1;
    }
    void setNum2(float num){
        num2 = num;
    }
    float getNum2(){
        return num2;
    }
    // -------------------- USER INPUT METHODS --------------------
    // Get input for the normal calculations [i.e. (+), (-), (×), and (÷)]
    void getInput(){
        float temp1,temp2 = 0.0;
        cout << "Please enter number 1: ";
        if(cin >> temp1){
            setNum1(temp1);
        }
        else{
            WrongType w;
            throw w;
        }
        cout << "Please enter number 2: ";
        if(cin >> temp2){
            setNum2(temp2);
        }
        else{
            WrongType w;
            throw w;
        }
    }
    // Get input for the special calculations [i.e. (√) and (x²)]
    void getInputSpecial(){
        float temp1 = 0.0;
        cout << "Please enter number: ";
        if(cin >> temp1){
            setNum1(temp1);
        }
        else{
            WrongType w;
            throw w;
        }
    }
private:
    float num1;
    float num2;
};
#endif /* Calculator_h */
