/*
Winning Lottery
Send Feedback
Harshit knows by his resources that this time the winning lottery number is the smallest number whose sum of the digits is S and the number of digits is D. You have to help Harshit and print the winning lottery number.
Input Format
The Input line contains two space-separated integers: S,D
Output Format
The output contains a single integer denoting the winning lottery number
Constraints
1 <= D <= 1000
1 <= S <= 9*D
Time Limit: 1 second
Sample Input1:
9 2
Sample Output1:
18
Explanation
There are many other possible numbers like 45, 54, 90, etc with the sum of digits as 9 and number of digits as 2. The smallest of them is 18.
*/


#include<bits/stdc++.h>
using namespace std;
int main() {

	int n;
    cin >> n;
    int d;
    cin >> d;
    int num = n-1;
    int* arr = new int[d];
    int index = d;
    d--;
    arr[0] = 1;
    int rem = num % 9;
    int div = num / 9;
    
    if(div > 0){
        while(div != 0){
            arr[d] = 9;
            div--;
            d--;
        }
        arr[d--] = rem;
        while(d != 0){
            arr[d--] = 0;
        }
    }else{
        arr[d--] = rem;
        while(d != 0){
            arr[d--] = 0;
        }
    }
   
    for(int i=0;i<index;i++){
        cout<< arr[i];
    }
    return 0;
}
