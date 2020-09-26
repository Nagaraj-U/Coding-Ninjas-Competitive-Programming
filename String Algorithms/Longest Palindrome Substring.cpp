#include<iostream>
using namespace std;

int longest_palindrome_substring(string str){
    int n = str.length();
    int maximum = 0;

    for(int i=0;i<n;i++){
        //odd
        int left = i;
        int right = i;
        while((left >=0 && right < n) && str[left] == str[right]){
            int len = right-left+1;
            maximum = max(maximum,len);
            left--;
            right++;
        }

        //Even
        left = i;
        right = i+1;
        while((left >= 0 && right < n) && str[left] == str[right]){
            int len = right - left + 1;
            maximum = max(maximum,len);
            left--;
            right++;
        }
    }

    return maximum;
}

int main(){

    string s;
    cout << " enter string " << endl;
    cin >> s;
    int ans = longest_palindrome_substring(s);
    cout << "longest palindromic substring length is : " << ans  << endl;
    return 0; 
}

//aabbccabcddcbapqrs
