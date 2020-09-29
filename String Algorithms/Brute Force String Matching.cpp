
#include<bits/stdc++.h>
using namespace std;

bool isFound(string s,string p,int &index){
    int n = s.length();
    int m = p.length();

    for(int i=0;i<=(n-m);i++){
        bool flag = true;
        index = i;
        for(int j=0;j<m;j++){
            if(s[i+j] != p[j]){
                flag = false;
            }
        }
        if(flag){
            return flag;
        }
    }
    return false;
}


int main(){

    string s,p;
    cout << "enter string" << endl;
    cin  >> s ;
    cout << "enter pattern" << endl;
    cin >> p;

    int index = 0;
    if(isFound(s,p,index)){
        cout << "string is found at index" << "  " << index << endl;
    }else{
        cout << "pattern not found" << endl;
    }
    return 0;
}
