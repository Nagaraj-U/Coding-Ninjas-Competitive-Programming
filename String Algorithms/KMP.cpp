#include<iostream>
using namespace std;

bool searchPattern(string text,string pattern,int* arr){
    int textLen = text.length();
    int patternLen = pattern.length();
    int i = 0;
    int j = 0;
    while(i < textLen && j < patternLen){
        if(text[i] == pattern[j]){
            i++;
            j++;
        }else{
            if(j != 0){
                j = arr[j-1];
            }else{
                i++;
            }
        }
    }

    if(j >= patternLen){
        return true;
    }else{
        return false;
    }
}

void getLPS(string str,int* arr){
    int i = 1;
    int j = 0;
    int len = str.length();
    arr[0] = 0;
    while(i < len){
        if(str[i] == str[j]){
            arr[i] = j+1;
            i++;
            j++;
        }else{
            if(j != 0){
                j = arr[j-1];
            }else{
                arr[i] = 0;
                i++;
            }
        }
    }
}


int main(){
    string pattern,text;
    cout << "Enter Text" << endl;
    cin >> text;

    cout << "Enter pattern " << endl;
    cin >> pattern;

    int* arr = new int[pattern.length()];
    getLPS(pattern,arr);

    cout << "Longest prefix which is also suffix array for pattern is : " << endl;
    for(int i=0;i<pattern.length();i++){
        cout << arr[i] << " ";
    }
    cout << endl;

    bool ans = searchPattern(text,pattern,arr);

    if(ans){
        cout << "Pattern found" << endl;
    }else{
        cout << "Pattern not found" << endl;
    }


    return 0;
}
