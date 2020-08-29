/*
14 : 1110 ; flipbit = 2
1110 ^ 0100 = 1010
(14,2) = 10
*/

#include<iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int i;
    cin >> i;
    int z;
    z = n ^ (1 << i);
    cout << z << endl;
    return 0;
}
