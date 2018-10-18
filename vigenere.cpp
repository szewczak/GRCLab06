/*
Author: Nick Szewczak
Course: CSCI-136
Instructor: Subhadarshi Panda
Assignment: Lab 5 Task C. Implementing Vigenere cipher encryption
Write a program vigenere.cpp. It should contain a function encryptVigenere implementing this cipher:
codeword    c a k e
plaintext   h e l l o,   w o r l d !
offset    + 2 0 A 4
cyphertext  j e v p q,   w y v n d !

string encryptVigenere(string plaintext, string keyword);
You may assume that the keyword contains only lowercase alphabetic characters a - z.

The main should implement a testing interface similar to the one in Task B, the user enters the plaintext and the keyword, and the program reports the ciphertext.

Example:
    $ ./vigenere

    Enter plaintext: Hello, World!
    Enter keyword  : cake
    Ciphertext     : Jevpq, Wyvnd!

*/

#include <iostream>
#include <string>
using namespace std;

int key(char a){                    //returns 0-25 for characters
    int temp = (int)a;
    if(temp >=97 && temp <= 122){
        return temp - 97;
    }
    else return -1;
}
char fromkey(int x){                // returns character from 0-25
    x+=26;
    return (char)((x%26)+97);
}

int myhash(string codeword){
    int static i = -1;
    i++;
    i%=codeword.length();
    return key(codeword[i]);
}

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

string encryptVigenere(string plaintext, string keyword){
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    for(int j=0; j<plaintext.length(); j++){
        tempchar = tolower(plaintext[j]);
        plainCASE = (plaintext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                output += fromkey(myhash(keyword)+key(tempchar));            
            }
            else{
                output += toupper(fromkey(myhash(keyword)+key(tempchar)));
            }
        }
        else{
            output += plaintext[j];
        }
    }
    return output;
}


int main(){
    string input = "";
    string saltword;
    cout << "Enter Plaintext: ";
    getline(cin, input); 
    cout << "Enter codeword: ";
    cin >> saltword;
    cout << "Ciphertext     : " << encryptVigenere(input, saltword) << endl;
    return 0;
}



