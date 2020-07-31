//  BasicCalculator.cpp
//
//  1) Subclass "BasicCalculator.cpp" inherits all the PROPERTIES and BEHAVIORS of the superclass "Calculator.h" apart from the Constructors and Destructors.
//
//  2) Public method: "BasicCalculator::calculate()" is accessible from the "driverProgram.cpp"... the private methods are hidden from the "driverProgram.cpp" so implementation details need not to be understood by the user interacting with the application! --> Should make the application easier to interact with
//
//  3) ***BONUS FEATURE*** [Bounds checking]
//  Exception handling is used in "BasicCalculator.cpp" so only VALID user inputs (i.e. = 1,2,3,4,5,6) are considered when interacting with displayMenu() to perform a calculation. If the data doesn't meet the standards, a customized exception message is displayed as seen in the OutOfRange class which prompts user to fix their mistake and keep code running.
//
//  Created by Adam Swanson on 2020-07-30.
//  Copyright © 2020 Adam Swanson. All rights reserved.
//
#include "Calculator.h"
#include <cmath>
#include <stdio.h>
#include <iostream>
#include <ctype.h>
#include <stdexcept>
using namespace std;

class BasicCalculator : public Calculator {
public:
// ------------------------------------------------- Constructor --------------------------------------------------
    BasicCalculator(){
        // Bounds-Checking Logic Explained:
        //      1) If initial input is VALID (i.e. = 1,2,3,4,5,6) displayMenu()
        //      2) Otherwise display ERROR MESSAGE from Customozed Exception Class
        try{
            displayMenu(); // Private class method to display "Basic Calculator" menu
        }
        catch(OutOfRange r) {
            cout << r.what() << endl; // Display "customized exception" message
            control = 0.0; // Used to Re-show "Main Menu"
        }
        catch(WrongType w){
            cout << w.what() << endl;
            exit(0); // Terminate program
        }
    }
// ------------------------------------------------- Destructor ---------------------------------------------------
    ~BasicCalculator(){}
// ----------------------------------------------- Calculate Method -----------------------------------------------
    void calculate(){
        while (flag){
            if(control == 1.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::add(getNum1(),getNum2());
                cout << "The sum of " << getNum1() << " (+) " << getNum2() << " = " << ans << endl << endl;
                // Error Handling
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 2.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::subtract(getNum1(), getNum2());
                cout << "The difference of " << getNum1() << " (-) " << getNum2() << " = " << ans << endl << endl;
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 3.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::multiply(getNum1(), getNum2());
                cout << "The product of " << getNum1() << " (×) " << getNum2() << " = " << ans << endl << endl;
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 4.0){
                try{
                    getInput(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::division(getNum1(), getNum2());
                cout << "The quotient of " << getNum1() << " (÷) " << getNum2() << " = " << ans << endl << endl;
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 5.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::squareRoot(getNum1());
                cout << "The root of " << getNum1() << " (√) " <<  " = " << ans << endl << endl;
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 6.0){
                try{
                    getInputSpecial(); // private class method to recieve user input
                } catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
                ans = Calculator::square(getNum1());
                cout << "The square of " << getNum1() << " (x²) " <<  " = " << ans << endl << endl;
                try{
                    control = displayMenu();
                }
                catch(OutOfRange r) {
                    cout << r.what() << endl;
                    control = 0.0;
                }
                catch(WrongType w){
                    cout << w.what() << endl;
                    exit(0); // Terminate program
                }
            }
            else if(control == 0.0){
                flag = false;
            }
        }
    }
private:
    // ------------------------------------------- Private Data Members -------------------------------------------
    float control = 0.0;
    float ans = 0.0;
    bool flag = true;
    // --------------------------------------------- Private Methods ----------------------------------------------
    // Display the "Basic Calculator Menu"
       float displayMenu(){
           cout << "---------- BASIC CALCULATOR ----------" << endl;
           cout << "Press 1: Add (+) \nPress 2: Subtract (-) \nPress 3: Multiply (×) \nPress 4: Divide (÷) \nPress 5: Square Root (√)\nPress 6: Square (x²) \n[Press 0:] Alternative Mode \nOption: ";
           if(cin >> control){
               if(control==1.0||control==2.0||control==3.0||control==4.0||control==5.0||control==6.0||control==0.0){
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
           return control;
       }
};
