/*
mod = primenumber = 37
abc = hash(abc) = (1 * 26^2 + 2 * 26 ^ 1 + 3 * 26 ^ 0) % mod
*/

#include<bits/stdc++.h>
using namespace std;
int mod = 13;

bool isMatch(string str,string pattern,int start,int end){
    for(int i=0;i<pattern.length();i++){
        if(pattern[i] != str[start++]){
            return false;
        }
    }
    return true;
}

int main()
{
    string str;
    string pattern;
    cin >> str >> pattern;

    int p_len = pattern.length()-1;
    int pattern_hash = 0;
    for(int i=0;i<pattern.length();i++){
        pattern_hash = pattern_hash % mod +  ((int)pow(26,(p_len-i))%mod * (pattern[i] - 'a' + 1) % mod) % mod;
        pattern_hash  = pattern_hash % mod;
    }

    int start = 0;
    int end = 0;
    int window_hash = 0;
    int n = str.length() - pattern.length();
    cout << n << endl;

    while(start <= n){
        window_hash = window_hash % mod + ((int)pow(26,p_len-(end - start))% mod  * (str[end] - 'a' + 1) % mod) % mod;
        window_hash = window_hash % mod;

        if(end-start+1 == pattern.length()){
    
            if(pattern_hash == window_hash){
                if(isMatch(str,pattern,start,end)){
                    cout << "match found " << " start index " << start << endl;
                    return 0; 
                }
            }

            //subtract starting char of window contribution in hash value
            window_hash = window_hash % mod - ((int)pow(26, p_len) % mod * (str[start] - 'a' + 1) % mod) % mod;
            
            //multiplying 26 to get , proper power values
            window_hash = (window_hash * 26) % mod;
            start++;
        }
        end++;
    }

    cout << "no match" << endl;
    return 0;
}

