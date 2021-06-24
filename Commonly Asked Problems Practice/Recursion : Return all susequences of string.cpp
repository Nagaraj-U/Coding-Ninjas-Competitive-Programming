#include<bits/stdc++.h>
using namespace std;

//SUBSETS IS SAME AS SUBSEQUENCES EXCEPT SUBSET HAS EMPTY STRING


void helper(string str,vector<string> &arr)
{
    if(str.length() == 0){
        arr.push_back("");
        return;
    }

    helper(str.substr(1),arr); // "abc" : call for "bc" then add "a" to all subsequences keeping original values

    int temp = arr.size();
    for(int i=0;i<temp;i++){ 
        arr.push_back(str[0] + arr[i]);
    }

    return;
}

int main()
{
    string str;
    cin>> str;
    int n = str.length();
    vector<string> arr;
    helper(str,arr);
    for(int i=0;i<arr.size();i++){
        cout << arr[i] << endl;
    }

    return 0;
}


/*
recursive tree

abc -> bc -> c -> ""

["","c","b","bc","a","ac","ab","abc"] <-- ["","c","b","bc"] <--  ["","c"]  <--  ""

*/




//finding subsequences using bit manipulation

// int main()
// {
//     string str;
//     cin >> str;
//     int n = str.length();
//     int size = (1<<n);
//     vector<string> v;
//     for(int i=0;i<size;i++){
//         string temp = "";
//         for(int j=0;j<32;j++){
//             if(i & (1<<j)){
//                 temp += str[j];
//             }
//         }
//         v.push_back(temp);
//     }

//     for(int i=0;i<v.size();i++){
//         cout << v[i] << endl;
//     }

//     return 0;
// }
