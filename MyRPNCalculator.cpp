// Programmer: Dhanush Patel
// Programmer's ID: 1553428

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

#include "Stack.h"

int main2(){
  Stack<string> mainStack;
  string input = "";
  Stack<string> stackDup;

  while(true){
    if(mainStack.empty()) {
      cout << "Enter: ";
    }
    else {
      string prompt = "Enter: ";
     while(!stackDup.empty()){
       prompt += stackDup.peek() + " ";
       stackDup.pop();
     }
      cout << prompt;
    }
    cin >> input;
    if(input == "Q" || input == "q"){
      break;
    }
    if((input == "+" || input == "*" || input == "/" || input == "-") && mainStack.size() < 2) {
    }
    else{
      if(mainStack.size() >= 2 && (input == "+" || input == "*" || input == "/" || input == "-")){
        double val1 = atof(mainStack.peek().c_str());
        mainStack.pop();
        double val2 = atof(mainStack.peek().c_str());
        mainStack.pop();
        double result = 0.0;
        if(input == "+"){
          result = val1 + val2;
        }
        else if(input == "*"){
          result = val1 * val2;
        }
        else if(input == "-"){
          result = val2 - val1;
        }
        else if(input == "/"){
          result = val2 / val1;
        }
        ostringstream strs;
        strs << result;
        mainStack.push(strs.str());
      }
      else {
        mainStack.push(input);
      }
    }
    stackDup = mainStack;
  }
}