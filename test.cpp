
#include <iostream>

using namespace std;

int key(char a){
    int temp = (int)a;
    if(temp >=97 && temp <= 122){
        return temp - 97;
    }
    else return -1;
}

char fromkey(int x){
    x+=26;
    return (char)((x%26)+97);
}
int main(){
    cout << fromkey(2) << endl;
    cout << fromkey(key('a')-1) << endl;
    cout << fromkey(key('z')+1);
    cout << endl;
    return 0;
}