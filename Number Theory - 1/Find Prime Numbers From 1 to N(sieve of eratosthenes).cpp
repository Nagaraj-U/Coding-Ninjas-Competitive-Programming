/*
Find Prime Numbers From 1 to N
Send Feedback
Given a number N, find number of primes in the range [1,N].
Input:
The only line of input consists of a number N
Output:
Print the number of primes in the range [1,N].`
Constraints:
1≤N≤1000000
Sample Input :
3 
Sample Output -
2
*/

// #include<iostream>
// using namespace std;

// bool isPrime(int n){
//     int countFactors = 0;
//     for(int j=1;j*j<=n;j++){
//         if((n%j) == 0){
//             if(j*j == n){
//                 countFactors += 1;
//             }else{
//                 countFactors +=2;
//             }
//         }
//     }
//     if(countFactors == 2){
//         return true;
//     }
//     return false;
// }

// int main(){
// 	// Write your code here
//     int n;
//     cin >> n;
//     int count = 0;
//     for(int i=1;i<=n;i++){
//         if(isPrime(i)){
//             count++;
//         }
//     }
//     cout << count << endl;
// 	return 0;
// }


//sieve of erathostenes
//complexity O(nloglogn)
#include<iostream>
using namespace std;
#include<math.h>
int main(){
    int n;
    cin >> n;
    bool* arr = new bool[n+1];
    for(int i=0;i<=n;i++){
        arr[i] = true;
    }
    arr[0] = false;
    arr[1] = false;
    
    for(int i=2;i<=sqrt(n);i++){
        if(arr[i]){
            // for(int j=i;j*i<=n;j++){
            //     arr[j*i] = false;
            //     // j = (j+i);
            // }
            for(int j=i*i;j<=n;j+=i){
                arr[j] = false;
            }
        }
    }
    
    
    
    int count = 0;
    for(int i=0;i<=n;i++){
        if(arr[i] == true){
            count++;
        }
    }
    cout << count ;
    return 0;
}
