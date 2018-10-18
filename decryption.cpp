/*
Author: Nick Szewczak
Course: CSCI-136
Instructor: Subhadarshi Panda
Assignment: Lab 5 Task D. Decryption
Implement two decryption functions corresponding to the above ciphers. When decrypting ciphertext, ensure that the produced decrypted string is equal to the original plaintext:

decryptCaesar(ciphertext, rshift) == plaintext
decryptVigenere(ciphertext, keyword) == plaintext
Write a program decryption.cpp that uses the above functions to demonstrate encryption and decryption for both ciphers.

It should first ask the user to input plaintext, then ask for a right shift for the Caesar cipher and report the ciphertext and its subsequent decryption. After that, it should do the same for the Vigenere cipher.

Example:
    $ ./decryption

    Enter plaintext: Hello, World!

    = Caesar =
    Enter shift    : 10
    Ciphertext     : Rovvy, Gybvn!
    Decrypted      : Hello, World!

    = Vigenere =
    Enter keyword  : cake
    Ciphertext     : Jevpq, Wyvnd!
    Decrypted      : Hello, World!
(When reporting decrypted strings, they should be the result of applying decryption functions to the ciphertext, not the original plaintext variable.)
*/

#include <iostream>
#include <string>
using namespace std;

///global index for Vigenere cipher
int vigenereIndex = -1;

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
    vigenereIndex++;
    vigenereIndex%=codeword.length();
    return key(codeword[vigenereIndex]);
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

string encryptCaesar(string plaintext, int rshift){
    string output;
    for(int i=0; i < plaintext.length(); i++){
    output += shiftChar(plaintext[i], rshift);
    }
    return output;
}

string encryptVigenere(string plaintext, string keyword){
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    vigenereIndex = -1; // reset for this Vigenere run
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

string decryptCaesar(string ciphertext, int rshift){    //negates caesar shift
    return encryptCaesar(ciphertext, 0-rshift);
}

string decryptVigenere(string ciphertext, string keyword){ //Reverse implementation of Vigenere Cipher
    string output;
    char tempchar;
    bool plainCASE = true; // if true, this is a lower case character
    vigenereIndex = -1; // reset for this Vigenere run
    for(int j=0; j<ciphertext.length(); j++){
        // cout << ciphertext[j] << endl;
        tempchar = tolower(ciphertext[j]);
        plainCASE = (ciphertext[j] == tempchar);

        if((int)tempchar >= 97 && (int)tempchar <= 122){
            if(plainCASE){
                output += fromkey(key(tempchar)-myhash(keyword));            
            }
            else{
                output += toupper(fromkey(key(tempchar)-myhash(keyword)));
            }
        }
        else output += ciphertext[j];
    }
    return output;
}


int main(){
    string input = "";
    int shift;
    string saltword;
    cout << "Enter Plaintext: ";
    getline(cin, input);
    cout << "= Caesar =\n Enter Shift    : ";
    cin >> shift;
    string caesarText = encryptCaesar(input, shift);
    cout << "Ciphertext     : " << caesarText << endl;
    cout << "Decrypted      : " << decryptCaesar(caesarText, shift) << endl << endl;

    cout << "= Vigenere = \n Enter keyword  : ";
    cin >> saltword;
    string vigenereText = encryptVigenere(input, saltword);
    cout << "Ciphertext     : " << vigenereText << endl;
    cout << "Decrypted      : " << decryptVigenere(vigenereText, saltword) << endl;
    
    
    return 0;
}