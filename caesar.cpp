/*
Author: Nick Szewczak
Course: CSCI-136
Instructor: Subhadarshi Panda
Assignment: Lab 5 Task B. Implementing Caesar cipher encryption
Write a program caesar.cpp with functions implementing Caesar cipher encryption:

    // A helper function to shift one character by rshift
    char shiftChar(char c, int rshift);

    // Caesar cipher encryption
    string encryptCaesar(string plaintext, int rshift);
The argument rshift is the magnitude of the right shift. For the sake of the lab, you may assume it to be in the range 0 ≤ rshift ≤ 25 (although, implementing it correctly for an arbitrary integer shift is also possible, of course).

Your functions should preserve case, and any non-alphabetic characters should be left unchanged. For example,

    encryptCaesar("Way to Go!", 5) == "Bfd yt Lt!"
Feel free to write more additional helper functions when you need them.

The main function should ask the user to input a plaintext sentence, then enter the right shift, and report the ciphertext computed using your encryption function.

Example:
    $ ./caesar

    Enter plaintext: Hello, World!
    Enter shift    : 10
    Ciphertext     : Rovvy, Gybvn!
*/

#include <iostream>
#include <string>

using namespace std;

char shiftChar(char c, int rshift){
    char temp = tolower(c);
    int raw = ((int)temp - 97 + rshift);
    raw += 26;
    raw =  raw % 26;
    raw += 97;
    temp = (char)raw;

    if((int)c >= 65 && (int)c <= 90){ // uppercase letters
        temp = toupper(temp);
        return temp;
    }

    if((int)c >= 97 && (int)c <= 122){ // lowercase letters
        return temp;
    }
    else{ //punctuation
        return c;
    }
}
string encryptCaesar(string plaintext, int rshift){
    string output;
    for(int i=0; i < plaintext.length(); i++){
    output += shiftChar(plaintext[i], rshift);
    }
    return output;
}


int main(){
    string input = "";
    int shift;
    cout << "Enter Plaintext: ";
    getline(cin, input); 
    cout << "Enter shift: ";
    cin >> shift;
    cout << "Ciphertext     : " << encryptCaesar(input, shift) << endl;
    return 0;
}



