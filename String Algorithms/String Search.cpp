/*
String Search
Send Feedback
Given two strings S and T, write a function to find if T is present as a substring inside S or not. If yes, return the starting index otherwise return -1.
Input format :

Line 1 : String S

Line 2 : String T

Sample Input 1:
WelcomeBack
come 
Sample Output 1:
3
Sample Input 2:
WelcomeBack
code
Sample Output 2:
-1

*/


#include <iostream>
using namespace std;

// You need to check if string pattern is present in text or not


//return longest-prefix-suffix array for pattern
void getLPS(char pattern[],int* arr,int patternlen){
    int i = 1;
    int j = 0;
    while(i < patternlen){
        if(pattern[i] == pattern[j]){
            arr[i] = j+1;
            i++;
            j++;
        }else{
            if(j != 0){
                j = arr[j-1];
            }else{
                arr[i] = 0;
                i++;
            }
        }
    }
    return;
}


int findString(char text[], char pattern[]) {
	int textlen = 0;
    int patternlen = 0;
    
    while(text[textlen] != '\0'){
        textlen++;
    }
    while(pattern[patternlen] != '\0'){
        patternlen++;
    }
    
    int* arr = new int[patternlen]();
    getLPS(pattern,arr,patternlen);
    
    int i = 0;
    int j = 0;
    while(i < textlen && j < patternlen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = arr[j-1];  //move to arr[j-1] which tells from where to start comparing again
            }else{
               i++; //No suffix prefix available
            }
        }
    }
    
    if(j >= patternlen){
        return (i-j); //return starting index
    }else{
        return -1;
    }
}


int main() {
    char S[1000], T[1000];
    cin.getline(S, 1000);
    cin.getline(T, 1000);
    cout << findString(S, T) << endl;
}
