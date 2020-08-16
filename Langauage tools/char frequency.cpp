/*
problem : return first non repeating character in string
if no repeating character found return first character of string
*/


#include<iostream>
#include<string>
#include<map>

using namespace std;

void first_char(string str){
    map<char,int> frequency;
    for(int i=0;i<str.length();i++){
        frequency[str[i]] = frequency[str[i]] + 1;  //incresing frequency everytime
    }
    for(int i=0;i<str.length();i++){
        if(frequency[str[i]] == 1){
            cout << str[i] << endl;
            return;
        }
    }
    cout << str[0] << endl;
    return;
}

int main(){
    string str;
    cout << "enter string " << endl;
    cin >> str;
    first_char(str);
    return 0;
}
