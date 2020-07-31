// Develop the generic function to multiply and divide two numbers of any data type
//

#include <iostream>
#include <stdio.h>
#include "BasicCalculator.cpp"
#include "ScientificCalculator.cpp"
#include "Calculator.h"
using namespace std;

float mainMenuController = 0.0;
// -------------------- DISPLAY METHOD --------------------
    void displayMain(){
        cout << "---------- MAIN MENU ----------" << endl;
        cout << "Press 1: Basic Calculator \nPress 2: Scientific Calculator \n[Press -1: Quit Program] \nOption: ";
        if(cin >> mainMenuController){
            if(mainMenuController==1||mainMenuController==2||mainMenuController==-1){
                ; //do nothing
            }
            else{
                OutOfRange r;
                throw r;
            }
        }
        else{
            mainMenuController = -1;
            WrongType w;
            throw w;
        }
        cout << endl;
    }

int main (){
    while(mainMenuController != -1.0){
        try{
            displayMain();
        }
        catch(OutOfRange r) {
            cout << r.what() << endl;
        }
        catch(WrongType w){
            cout << w.what() << endl;
        }
        
        if(mainMenuController == 1.0){
            BasicCalculator calculateBasic;
            calculateBasic.calculate();
        }
        else if(mainMenuController == 2.0){
            ScientificCalculator calculateScience;
            calculateScience.calculate();
        }
        else if(mainMenuController == -1.0){
            cout << "";
        }
    }
  return 0;
}

// TESTING THAT THE METHODS WORK CORRECTLY
/*float num1, num2, answer;
// test by changing float to int or double. Do you have any other change in the program?
cout << "Please enter integer 1 : ";
cin >> num1;
cout << "Please enter integer 2 : ";
cin >> num2;

ScientificCalculator calculate;
cout << "---------- SCIENCE ----------" << endl;
answer = calculate.add(num1, num2);
cout << "The sum of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.subtract(num1, num2);
cout << "The difference of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.multiply(num1, num2);
cout << "The multiplication of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.division(num1, num2);
cout << "The division of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.square(num1);
cout << "The square of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.squareRoot(num1);
cout << "The square root of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.sine(num1);
cout << "The sin of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.cosine(num1);
cout << "The cos of " << num1 << " & " << num2 << " = " << answer << endl;
answer = calculate.tangent(num1);
cout << "The tan of " << num1 << " & " << num2 << " = " << answer << endl;
cout << "---------- BASIC ----------" << endl;
BasicCalculator calc2;
answer = calc2.add(num1,num2);
cout << "The sum of " << num1 << " & " << num2 << " = " << answer << endl;*/

