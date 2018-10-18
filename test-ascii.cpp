/*
Author: Nick Szewczak
Course: CSCI-136
Instructor: Subhadarshi Panda
Assignment: Lab 5 task A

Write a program test-ascii.cpp that asks the user to input a line of text (which may possibly include spaces). The program should report all characters from the input line together with their ASCII codes.

Make sure to print exactly one space between the character and it’s code.

Example:
    $ ./test-ascii

    Input: Cat :3 Dog

    C 67
    a 97
    t 116
    32
    : 58
    3 51
    32
    D 68
    o 111
    g 103
Hint:
When you are printing a value of type char on the screen, it is normally shown as a symbol. To print it as a number (as its ASCII code), type cast it to integer:

cout << (int)c;
*/

#include <iostream>

using namespace std;

int main(){
    string input = "";
    cout << "Input: ";
    getline(cin, input); 
    // cout << input << endl;
    for(int i=0; i < input.length(); i++){
        cout << input[i] << " " << (int)input[i] << endl;
    }
    
    return 0;
}