//#include<iostream>
//#include<algorithm>
#include<bits/stdc++.h>  //this includes all the libraries

using namespace std;

int main(){
    int arr[] = {1,4,3,56,78,94,34,2};
    sort(arr,arr+8);
   // sort(arr,arr+8,greater<int>());  //sorts them in decreasing order
    for(int i=0;i<8;i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << binary_search(arr,arr+8,4) << endl; //returns 1 for found

    cout << "lower bound index is " << lower_bound(arr,arr+8,3) - arr << endl;

    cout << "upper bound idex is " << upper_bound(arr,arr+8,34) - arr << endl; //this returns next index doing -1 gives answer

    cout<<endl;
    cout << "GCD " <<  __gcd(10,5) << endl;
    cout << "power " << pow(2,5) << endl;
    cout << "max " << max(10,15) << endl;
    cout << "min " << min(2,3) << endl;

    return 0;
}
