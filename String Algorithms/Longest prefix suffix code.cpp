#include<iostream>
using namespace std;

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
    string pattern;
    cout << "Enter pattern " << endl;
    cin >> pattern;
    int* arr = new int[pattern.length()];
    getLPS(pattern,arr);
    for(int i=0;i<pattern.length();i++){
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
