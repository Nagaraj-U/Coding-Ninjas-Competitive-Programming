/*

Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf
*/




#include <iostream>
#include <string>
#include "solution.h"
using namespace std;
#include<string>
const char key[10][5]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};  // 10 strings each of max size 5 
using namespace std;

int keypad(int n, string output[]){
    /* Insert all the possible combinations of the integer number into the output string array. You do not need to
    print anything, just return the number of strings inserted into the array.
    */
    
    if(n == 0){
        output[0] = "";
        return 1;
    }
    int rem = n % 10;   //storing last digit from number
    n = n/10;  //passing number for recursive call except last digit
    
    //doing recursive call on number except last digit of number
    
    int smallOutputSize = keypad(n,output);
    string arr[smallOutputSize];  //to store all strings obtained from recursive call
    for(int i=0;i<smallOutputSize;i++){
        arr[i] = output[i];    //copying original array elements
    }
    int j = 0;
    int temp = 0;
    while(key[rem][j] != '\0'){    //appending all char from rem (last digit) to obtained array
        for(int i=0;i<smallOutputSize;i++){
            output[i+temp] = arr[i] + key[rem][j];
        }
        temp += smallOutputSize;  //to append next char in 'rem' digit
        j++;  //next char in 'rem' digit
    }   
    return temp;
}



int main(){
    int num;
    cin >> num;

    string output[10000];
    int count = keypad(num, output);
    for(int i = 0; i < count && i < 10000; i++){
        cout << output[i] << endl;
    }
    return 0;
}
