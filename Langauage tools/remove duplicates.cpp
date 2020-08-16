//#include<bits/stdc++.h>
#include<iostream>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;

void removeDuplicates(vector<int> v){

    cout << "SOLUTION 1 : "<< endl;
    //making use of set
    set<int> s;
    vector<int> result;
    for(int i=0;i<v.size();i++){
        if(s.find(v[i]) == s.end()){   //inserting if element not in set
            s.insert(v[i]);
            result.push_back(v[i]);
        }
    }
    cout << "array with duplicates removed : " << endl;
    for(int i=0;i<result.size();i++){
        cout << result[i] << " ";
    }
    cout << endl;
    cout << "SOLUTION 2 : " << endl;
    //sorting and then removing duplicates which comes together
    sort(v.begin(),v.end());
    vector<int> result1;
    result1.push_back(v[0]);
    for(int i=1;i<v.size();i++){
        if(v[i] != v[i-1]){
            result1.push_back(v[i]);
        }
    }
    cout << "duplicates removed array : " << endl;
    for(int i=0;i<result1.size();i++){
        cout << result1[i] << " ";
    }
}

int main(){
    vector<int> v;
    vector<int>::iterator it;
    cout << "enter number of elements " << endl;
    int n;
    cin >> n;

    for(int i=0;i<n;i++){
       int num;
       cin >> num;
       v.push_back(num);
    }
    removeDuplicates(v);

    return 0;
}
