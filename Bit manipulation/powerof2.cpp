/*
8 : 1000
7 : 0111
8 & 7 : 0000  
power of two
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    if((n & n-1) == 0){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
    return 0;
}
