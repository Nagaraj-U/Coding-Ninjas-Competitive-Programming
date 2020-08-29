/*
Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.
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
using namespace std;

#include <iostream>
#include <string>
using namespace std;
string output[1000];
const char key[10][5]={{},{},{'a','b','c'},{'d','e','f'},{'g','h','i'},{'j','k','l'},{'m','n','o'},{'p','q','r','s'},{'t','u','v'},{'w','x','y','z'}};

void helper(int n,string output){
  if(n==0){
   
    cout<<output<<endl;
    return;
  }
  
    int temp=n%10;
	n=n/10;
  	int j=-1;
  	while(key[temp][++j]!='\0'){
    helper(n,key[temp][j]+output); 
    }
  
  
}

void printKeypad(int n){
    /*
    Given an integer number print all the possible combinations of the keypad. You do not need to return anything just print them.
   */
 helper(n,"");
}

int main(){
    int num;
    cin >> num;

    printKeypad(num);

    return 0;
}
