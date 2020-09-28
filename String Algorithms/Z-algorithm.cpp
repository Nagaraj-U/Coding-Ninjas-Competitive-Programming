#include<iostream>
using namespace std;


void buildArray(string str,int* arr){
    int left = 0;
    int right = 0;
    int n = str.length();
    for(int i=1;i<n;i++){
        if(i > right){
            left = i;
            right = i;
            while(right < n && str[right-left] == str[right]){
                right++;
            }
            arr[i] = right - left;
            right -- ;
        }else{
            int k = i - left;
            if(arr[k] <= (right-i)){
                arr[i] = arr[k];
            }else{
                left = i;
                while(right < n && str[right-left] == str[right]){
                    right++;
                }
                arr[i] = right - left;
                right--;
            }
        }
    }
    return ;
}

void searchString(string text,string pattern){
    string str = pattern+"$"+text;
    int n = str.length();
    int* arr = new int[n]();
    buildArray(str,arr);
    for(int i=0;i<n;i++){
        if(arr[i] == pattern.length()){
            cout << "pattern found at " << i-pattern.length()-1 << endl;
        }
    }
}

int main(){
    string text;
    string pattern;
    cout << "Enter Text" << endl;
    cin >> text;
    cout << "Enter pattern" << endl;
    cin >> pattern;
    searchString(text,pattern);
    return 0;
}
