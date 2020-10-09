#include<iostream>
#include<math.h>
using namespace std;

//Time complexity O(n^2)
bool isPrime1(int n){
    int countFactors = 0;
    for(int j=1;j<=n;j++){
        if((n%j) == 0){
            countFactors++;
        }
    }
    if(countFactors == 2){ //prime number has only 2 factors
        return true;
    }
    return false;
}



//Time complexity O(n^3/2)
/*
example : 9
1*9
3*3
9*1

if one factor is less than sqrt(n) then other is greater than sqrt(n) so instead of checking for greater factor increase count by 2 at a time
increase count by 1 only if number i*i = n example : 3*3 increase count by 1 
*/
bool isPrime(int n){
    int countFactors = 0;
    for(int j=1;j*j<=n;j++){
        if((n%j) == 0){
            if(j*j == n){
                countFactors += 1;
            }else{
                countFactors += 2;
            }
        }
    }
    if(countFactors == 2){
        return true;
    }

    return false;
}


int main(){
    int n;
    cout << "enter number " << endl;
    cin >> n;
    int count = 0;
    int count1 = 0;
    for(int i=1;i<=n;i++){
        if(isPrime(i)){
            count++;
        }

        if(isPrime1(i)){
            count1++;
        }
    }
    cout << "number of prime numbers between 1 to n is : " << count << endl;
    cout << "number of prime numbers between 1 to n is : " << count1 << endl;
    return 0;
}
