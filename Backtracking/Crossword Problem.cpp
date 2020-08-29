/*
CodingNinjas has provided a crossword of 10*10 grid. The grid contains '+' or '-' as its cell values. Now, you are also provided with a word list that needs to placed accurately in the grid. Cells marked with '-' are to be filled with word list.
For example, The following is an example for the input crossword grid and the word list.
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Output for the given input should be:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
Note: We have provided such test cases that there is only one solution for the given input.
Input format:
The first 10 lines of input contain crossword. Each of 10 lines has a character array of size 10. Input characters are either '+' or '-'.
The next line of input contains the word list, in which each word is separated by ';'. 
Output format:
Print the crossword grid, after placing the words of word list in '-' cells.  
Sample Test Cases:
Sample Input 1:
+-++++++++
+-++-+++++
+-------++
+-++-+++++
+-++-+++++
+-++-+++++
++++-+++++
++++-+++++
++++++++++
----------
CALIFORNIA;NIGERIA;CANADA;TELAVIV
Sample Output 1:
+C++++++++
+A++T+++++
+NIGERIA++
+A++L+++++
+D++A+++++
+A++V+++++
++++I+++++
++++V+++++
++++++++++
CALIFORNIA
*/








#include<iostream>
#include<bits/stdc++.h>
#include<vector>
#include<string>
using namespace std;
#define n 10

void printer(char cross[n][n]){
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout << cross[i][j] ;
        }
        cout << endl;
    }
}

bool isValidVertical(char cross[n][n],int r,int c,string word){
    int j = r;
    for(int i=0;i<word.length();i++){
        if(j > 9){
            return false;
        }
        if(cross[j][c] == '+' || ((cross[j][c] != '-' && cross[j][c] != word[i]))){
            return false;
        }
        if(cross[j][c] == '-' || cross[j][c] == word[i]){
            j++;
        }
    }
    return true;
}

void setVertical(char cross[n][n],int r,int c,vector<bool>& v,string word){
    for(int i=0;i<word.length();i++){
        if(cross[r+i][c] == '-'){
            cross[r+i][c] = word[i];
            v.push_back(true);
        }else{
            v.push_back(false);
        }
    }
}

void resetVertical(char cross[n][n],int r,int c,vector<bool> v){
    int row = r;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            cross[row+i][c] = '-';
        }
    }
}

bool isValidHorizontal(char cross[n][n],int r,int c,string word){
    int j = c;
    for(int i=0;i<word.length();i++){
        if(j > 9){
            return false;
        }
        if(cross[r][j] == '+' || (cross[r][j] != '-' && cross[r][j] != word[i])){
            return false;
        }
        if(cross[r][j] == '-' || cross[r][j] == word[i]){
            j++;
        }
    }
    return true;
}

void setHorizontal(char cross[n][n],int r,int c,vector<bool>& v,string word){
    for(int i=0;i<word.length();i++){
        if(cross[r][c+i] == '-'){
            cross[r][c+i] = word[i];
            v.push_back(true);
        }else{
            v.push_back(false);
        }
    }
}

void resetHorizontal(char cross[n][n],int r,int c,vector<bool> v){
    int col = c;
    for(int i=0;i<v.size();i++){
        if(v[i]){
            cross[r][col+i] = '-';
        }
    }
}


bool crossword(char cross[n][n],vector<string> words,int index){
    if(index >= words.size()){
        printer(cross);
        return true;
    }
    
    for(int r=0;r<n;r++){
        for(int c=0;c<n;c++){
            
            if(cross[r][c] == '-' || cross[r][c] == words[index][0]){
                if(isValidVertical(cross,r,c,words[index])){
                    vector<bool> helper;
                    setVertical(cross,r,c,helper,words[index]);
                    
                    if(crossword(cross,words,index+1)){
                        return true;
                    }
                    
                    resetVertical(cross,r,c,helper);
                }
                
                if(isValidHorizontal(cross,r,c,words[index])){
                    vector<bool> helper;
                    setHorizontal(cross,r,c,helper,words[index]);
                    
                    if(crossword(cross,words,index+1)){
                        return true;
                    }
                    resetHorizontal(cross,r,c,helper);
                }
            }
        }
    }
    return false;
}

int main(){
    char cross[n][n];
    for(int i=0;i<n;i++){
        string s;
        cin >> s;
        for(int j=0;j<n;j++){
            cross[i][j] = s[j];
        }
    }
    vector<string> words;
    string s;
    cin >> s;
    for(int i=0;i<s.length();i++){
        int j = i;
        while(s[j] != ';' && j < s.length()){
            j++;
        }
        words.push_back(s.substr(i,j-i));
        i = j; 
    }
    bool ans = crossword(cross,words,0);
    
    return 0;
}

