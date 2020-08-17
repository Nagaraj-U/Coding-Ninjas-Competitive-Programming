/*
Given a string, you need to remove all the duplicates. That means, the output string should contain each character only once. The respective order of characters should
remain same.
Input format :
String S
Output format :
Output String
Constraints :
0 <= Length of S <= 10^8
Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde

*/

#include<iostream>
using namespace std;
#include "solution.h"

#include<map>

char* uniqueChar(char *str){
    // Write your code here
    
	map<char, int> m;
    char *arr = new char[1000];//give size anything as it is dynamic 
    int index = 0;
    int i=0;
    while(str[i] != '\0'){
        if(m[str[i]] == 0){
            arr[index] = str[i];
            m[str[i]] += 1;
            index++;
        }
        i++;
    }
    arr[index] = '\0';
    return arr;
    
     
    
}

int main() {

	char input[1000000];
	cin >> input;
	cout << uniqueChar(input) << endl;
}
