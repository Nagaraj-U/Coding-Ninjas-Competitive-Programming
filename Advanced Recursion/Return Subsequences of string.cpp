/*
Given a string we need to find all subsequences and total count of subsequences
example : abc
output : 
total count = 2^3 =8
subsequences  = "",a,b,c,ab,ac,bc,abc
*/


#include<iostream>
#include<bits/stdc++.h>
using namespace std;

long subSeq(string str,string output[]){
    if(str.size() == 0){
        output[0] = "";
        return 1;
    }
    string smallString = str.substr(1); //calling except first character ie if "abc" call on "bc"
    long smallOutputSize  = subSeq(smallString,output);
    for(long i=0;i<smallOutputSize;i++){
        output[i+smallOutputSize] = str[0] + output[i];  //copying all substrings and adding first char of string
    }
    return 2 * smallOutputSize;  //doubling size
}

int main(){
    string str;
    cin >> str;
    string* output = new string[1000];
    long count = subSeq(str,output);
    cout << " Number of subsequences is : " << count << endl;
    for(long i=0;i<count;i++){
        cout << output[i] << endl;
    }
    return 0;
}
