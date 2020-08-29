/*
7 : 0111 
0111 & 0001 = 0001 (!= 0) hence odd

6 : 0110 
0110 & 0001 = 0000 (= 0) hence even
 */


#include<iostream>
using namespace std;
int main(){
    int n;
    cin >> n;
    if((n & 1) == 0){
        cout << "even" << endl;
    }else{
        cout << "odd" << endl;
    }
    return 0;
}
