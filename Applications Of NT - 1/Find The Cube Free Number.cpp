/*
Find The Cube Free Number
Send Feedback
A cube free number is a number who’s none of the divisor is a cube number (A cube number is a cube of a integer like 8 (2 * 2 * 2) , 27 (3 * 3 * 3) ). So cube free numbers are 1, 2, 3, 4, 5, 6, 7, 9, 10, 11, 12, 13, 14, 15, 17, 18 etc (we will consider 1 as cube free). 8, 16, 24, 27, 32 etc are not cube free number. So the position of 1 among the cube free numbers is 1, position of 2 is 2, 3 is 3 and position of 10 is 9. Given a positive number you have to say if its a cube free number and if yes then tell its position among cube free numbers.
Input
First line of the test case will be the number of test case T (1 <= T <= 100000) . Then T lines follows. On each line you will find a integer number n (1 <= n <= 1000000).
Output
For each input line, print a line containing “Case I: ”, where I is the test case number. Then if it is not a cube free number then print “Not Cube Free”. Otherwise print its position among the cube free numbers.
Sample Input:
10
1
2
3
4
5
6
7
8
9
10
Sample Output:
Case 1: 1
Case 2: 2
Case 3: 3
Case 4: 4
Case 5: 5
Case 6: 6
Case 7: 7
Case 8: Not Cube Free
Case 9: 8
Case 10: 9
*/

#include<iostream>
using namespace std;
#define MAX 1000001

int main(){
	// Write your code here
    int t;
    cin >> t;
    
    //pre computing array 
    int* arr = new int[MAX]();
    for(int i=0;i<=1000000;i++){
        arr[i] = 0;
    }
    for(int i=2;i<=100;i++){ //its enough if you traverse upto 100 since (100)^3 = 10^6 by time you reach 100 it covers remaining all
        int cubic = i*i*i;
        for(int j=1;cubic*j<=1000000;j++){ //making all cubic numbers of i to -1
            arr[cubic*j] = -1;
        }
    }
    
    int* result = new int[MAX]();//at each index it stores numbers of cubic free numbers ending at that index(ie position)
    int count = 1;
    result[0] = 0;
    for(int i=1;i<=1000000;i++){
        if(arr[i] != -1){
            result[i] = count;
            count++;
        }
    }
    
    int caseCount = 1;
    while(t--){
        int n;
        cin >> n;
        if(result[n] == 0){
            cout << "Case " << caseCount << ": " << "Not Cube Free" << endl; 
            caseCount++;
        }else{
            cout<<"Case " << caseCount << ": " << result[n] << endl;
            caseCount++;
        }
    }
	return 0;
}
