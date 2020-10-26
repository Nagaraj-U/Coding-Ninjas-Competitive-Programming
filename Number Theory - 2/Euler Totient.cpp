#include <iostream>
using namespace std;

/*
EULER TOTIENT FUNCTION : TO FIND NUMBER OF CO-PRIMES THAT ARE LESSER THAN THE GIVEN NUMBER 'N'

f(n) = f(p1^a)*f(p2^b)*f(p3^c)* ... f(pk^z)  : every number can be expresses as product of primes : example -> 6 = 2*3 
where p1,p2,..pk are distinct prime factors of 'n' and a,b,c...z are powers of prime numbers

according to euler totient function number of co-primes lesser than given number is given by equation
f(n) = n * (1 - (1/p1) ) * (1 - (1/p2) ) * (1 - (1/p3) ) * .....(1 - (1/pk) )

*/

/*
Tracing algorithm: 

step 1 : initialize array with that index value : ie arr[2] = 2, arr[5] = 5 this is coz we are multiplying by 'n' in equation

step 2 : traverse array for 1 to n
if :
1. arr[i] is prime(can be checked by if number is modified by their previous terms then its not prime) 
    then make arr[i] = i-1 this coz example: for prime 5 number of co-primes are 5 , similarly for 17 it is 16
2. traverse to all multiples of 'i' and multiply their value by (1 - (1/i)) or (i-1)/i   
    coz if number is primes all multiples of it have this number in thier prime factors ,as equation says

example: 
1,2,3,4,5,6,7 original array

0,2,3,4,5,6,7  i=1 : no elements are lesser than 1 are co-primes
0,2,3,4,5,6,7  : i=2 : arr[i] = i means prime make arr[i] = i-1 and multiple of 2 are multiplied by (1 - (1/2))
0,1,3,2,5,3,7  : i=3 : prime
0,1,2,2,5,2,7  ; i=4 : not prime since arr[i] != i
0,1,2,2,5,2,7  : i=5 : prime
0,1,2,2,4,2,7  : i=6 : not prime
0,1,2,2,4,2,7  : i=7 : prime
0,1,2,2,4,2,7  final result

1,2,3,4,5,6,7 -> 0,1,2,2,4,2,7  ex:  for number  = 6 there are 2 co-primes(1,5)
*/

int main(){
    int arr[1001];
    for(int i=1;i<1001;i++){
        arr[i] = i;
    }
    
    for(int i=2;i<=1000;i++){
        if(arr[i] == i){
            arr[i] = i-1;
            for(int j=2*i;j<=1000;j+=i){
                arr[j] = (arr[j] * (i-1))/i;
            }
        }
    }

    //queries
    cout << "Enter the number for which you want to find number of co-primes lesser than that " << endl;
    int q1;
    cin >> q1;
    cout << "Number of co-primes which are lesser than " << q1 << " are " << arr[q1] << endl; 

    cout << "Enter the number for which you want to find number of co-primes lesser than that " << endl;
    int q2;
    cin >> q2;
    cout << "Number of co-primes which are lesser than " << q2 << " are " << arr[q2] << endl; 

    return 0;
}
