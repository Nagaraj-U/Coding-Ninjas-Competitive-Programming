/*

Advanced GCD
Send Feedback
Varun explained its friend Sanchit the algorithm of Euclides to calculate the GCD of two numbers. Then Sanchit implements the algorithm
int gcd(int a, int b)
{

    if (b==0)
    return a;
    else
    return gcd(b,a%b);
}
and challenges to Varun to calculate gcd of two integers, one is a little integer and other integer has 250 digits.
Your task is to help Varun an efficient code for the challenge of Sanchit.
Input
The first line of the input file contains a number representing the number of lines to follow. Each line consists of two number A and B (0 <= A <= 40000 and A <= B < 10^250).
Output
Print for each pair (A,B) in the input one integer representing the GCD of A and B..
Sample Input:
2
2 6
10 11
Sample Output:
2
1

*/

#include<iostream>
using namespace std;
#include<string>

int gcd(int a,int b){
 
    if(b == 0){
        return a;
    }else{
        return gcd(b,a%b);
    }
}

//gcd(a,b) = gcd(b,a%b)
//gcd(10,10^250) storing 10^250 in string and getting 10^250 in range of 'a' by taking modulo
//ie example gcd(40,5326) getting 5326 within range of 40   (a = 40, b = 5326)
//5 = (10*0 + 5)%40 = 5
//53%40 = (5*10 % 40 + 3%40)%40 = (10+3) = 13
//532%40 = (13*10 % 40 + 2 % 40) % 40 = (10 + 2) = 12  ie (532 % 40 = 12) this is how modulo of 5326 is built
//initially current = 0  -> current = (current*10 % 40 + b[i]-'0' % 40) % 40
//(a+b)%c = (a%c + b%c)%c

int main(){
	int t;
    cin >> t;
    while(t--){
        int a;
        string b;
        cin >> a >> b;
        if(a == 0){
            cout << b << endl;
            continue;
        }
        int current = 0;
        for(int i=0;i<b.size();i++){
            current = ( ((current*10) % a) + ((b[i] - '0') % a) ) % a; //now b is in range of integers
        }
        cout << gcd(current,a) << endl; 
    }
	return 0;
}
