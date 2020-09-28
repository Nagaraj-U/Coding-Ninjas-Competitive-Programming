/*
Search Engine

Let us see how search engines work. Consider the following simple auto complete feature. When you type some characters in the text bar, the engine automatically gives best matching options among it's database. Your job is simple. Given an incomplete search text, output the best search result.
Each entry in engine's database has a priority factor attached to it. We consider a result / search suggestion best if it has maximum weight and completes the given incomplete search query. For each query in the input, print the maximum weight of the string in the database, that completes the given incomplete search string. In case no such string exists, print -1.
INPUT
First line contains two integers n and q, which represent number of database entries and number of search queries need to be completed. Next n lines contain a string s and an integer weight, which are the database entry and it's corresponding priority.

Next q lines follow, each line having a string t, which needs to be completed.
OUTPUT
Output q lines, each line containing the maximum possible weight of the match for given query, else -1, in case no valid result is obtained.
CONSTRAINTS
1 ≤ n, weight, len(s), len(t) ≤ 10^6
1 ≤ q ≤ 10^5
total length of all strings in database entries ≤ 10^6
total length of all query strings ≤ 10^6
SAMPLE INPUT
2 1
hackerearth 10
hackerrank 9
hacker
SAMPLE OUTPUT
10
*/


#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    Trie** children;
    int weight;
    
    Trie(){
        children = new Trie*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        weight = 0;
    }
};

void insert(string str,int weight,Trie* root){
    if(str.empty()){
        return;
    }
    Trie* child;
    int index = str[0] - 'a';
    if(root->children[index]){
        child = root->children[index];
    }else{
        child = new Trie();
        root->children[index] = child;
    }
    if(root->weight < weight){
        root->weight = weight;
    }
    
    insert(str.substr(1),weight,child);
    return;
}

int findBestWeight(string str,Trie* root){
    int best_weight = -1;
    Trie* current = root;
    for(int i=0;i<str.length();i++){
        int index = str[i] - 'a';
        Trie* child = current->children[index];
        if(child){
            current = child;
            best_weight = child->weight;
        }else{
            return -1;
        }
    }
    return best_weight;
}

int main()
{
    int n,q;
    cin >> n >> q;
    Trie* root = new Trie();
    while(n--){
        string str;
        int weight;
        cin >> str;
        cin >> weight;
        insert(str,weight,root);
    }
    
    while(q--){
        string str;
        cin >> str;
        cout << findBestWeight(str,root) << endl;
    }
    return 0;
}
