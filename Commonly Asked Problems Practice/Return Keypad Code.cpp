
/*
Given an integer n, using phone keypad find out all the possible strings that can be made using digits of input n.
Return empty string for numbers 0 and 1.
Note : 1. The order of strings are not important.
2. Input and output has already been managed for you. You just have to populate the output array and return the count of elements populated in the output array.
Input Format :
Integer n
Output Format :
All possible strings in different lines
Constraints :
1 <= n <= 10^6
Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf


*/



#include <string>
using namespace std;

char arr[10][5] = {"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
int len[] = {0,0,3,3,3,3,3,4,3,4};

//RECURSIVE
int helper(int n,string output[]){
    if(n == 0){
        output[0] = "";
        return 1;
    }
    
    int rem = n%10;
    n = n/10;
    int size = helper(n,output);
    string temp[size];
    for(int i=0;i<size;i++){
        temp[i] = output[i];
    }
    
    int index = 0;
    int tempSize = 0;
    while(arr[rem][index] != '\0'){
        for(int i=0;i<size;i++){
            output[i+tempSize] = temp[i] + arr[rem][index];
        }
        tempSize += size;
        index++;
    }
    
    return tempSize;
}


//ITERATIVE
int helper(int n,string output[])
{
    int size = 0;
    while(n != 0){
        int rem = n%10;
        n = n/10;
        
        if(size == 0){
            int curr = len[rem];
            int idx = 0;
            while(arr[rem][idx]!='\0'){
                output[idx] = arr[rem][idx];
                idx++;
                size++;
            }
            continue;
        }
        
        string temp[size];
        for(int i=0;i<size;i++){
            temp[i] = output[i];
        }
        
        int index = 0;
        int tempSize = 0;
        while(arr[rem][index] != '\0'){
            for(int i=0;i<size;i++){
                output[i+tempSize] = arr[rem][index] + temp[i];
            }
            index++;
            tempSize += size;
        }
        
        size = tempSize;
    }
    
    return size;
}

int keypad(int num, string output[]){
    
    return helper(num,output);
    
}
