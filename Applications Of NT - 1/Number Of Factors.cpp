/*
Number Of Factors
Send Feedback
A number is called n-factorful if it has exactly n distinct prime factors. Given positive integers a, b, and n, your task is to find the number of integers between a and b, inclusive, that are n-factorful. We consider 1 to be 0-factorful.
Input
Your input will consist of a single integer T followed by a newline and T test cases. Each test cases consists of a single line containing integers a, b, and n as described above.
Output
Output for each test case one line containing the number of n-factorful integers in [a, b].
Constraints
T < 10000

1 ≤ a ≤ b ≤ 10^6

0 ≤ n ≤ 10
Sample Input
5
1 3 1
1 10 2
1 10 3
1 100 3
1 1000 0
Sample Output
2 
2
0
8
1
*/

#include<iostream>
using namespace std;
#define MAX 1000001

void makesieve(int* arr){
    for(int i=0;i<MAX;i++){
        arr[i] = 0;
    }
    
    for(int i=2;i<MAX;i++){
        if(arr[i] == 0){
            for(int j=1;i*j<MAX;j++){ //every time increasing factor by 1
                arr[j*i] += 1;
            }
        }
    }
    return;
}

int main(){
	// Write your code here
    int t;
    cin >> t;
    int* sieve = new int[MAX];
    makesieve(sieve);  
    
    int** table = new int*[11];//stores count of each value of sieve (example what is count of number 8 with n=3)
    for(int i=0;i<11;i++){
        table[i] = new int[MAX];
    }
    for(int i=0;i<11;i++){
        table[i][0] = 0;
        table[i][1] = 0;
        for(int j=2;j<MAX;j++){
            if(sieve[j] == i){
                table[i][j] = table[i][j-1]+1;//storing previous + present count (count upto that index)
            }else{
                table[i][j] = table[i][j-1];
            }
        }
    }
    while(t--){
        int a,b,n;
        cin >> a >> b >> n;
        
        //special case
        if(a==1 && n==0){ //given
            cout << 1 << endl;
            continue;
        }
        int ans = table[n][b] - table[n][a-1];
        cout << ans << endl;
        
    }
	return 0;
}
