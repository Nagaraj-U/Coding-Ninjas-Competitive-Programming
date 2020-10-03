/*
Help Me Pradyumana!
Send Feedback
Pradyumn is tired of using auto - correct feature in his smartphone. He needs to correct his auto - correct more times than the auto - correct corrects him. Pradyumn is thinking to make his own app for mobile which will restrict auto - correct feature, instead it will provide auto - completion. Whenever Pradyumn types factorial, auto - correct changes it to fact. Pradyumn's App will show options such as fact, factorial, factory. Now, he can chose from any of these options. As Pradyumn is busy with his front - end work of his App. He asks you to help him. He said "You will be given set of words(words may repeat too but counted as one only). Now, as user starts the app, he will make queries(in lowercase letters only). So, you have to print all the words of dictionary which have the prefix same as given by user as input. And if no such words are available, add this word to your dictionary." As you know, Pradyumn want this app to be as smart as him :P So, implement a program for him such that he can release it on Fun Store.
INPUT CONSTRAINTS
1≤N≤30000
sum(len(string[i]))≤2∗10^5
1≤Q≤10^3
INPUT FORMAT
Single integer N which denotes the size of words which are input as dictionary
N lines of input, where each line is a string of consisting lowercase letter
Single integer Q which denotes the number of queries.
Q number of lines describing the query string on each line given by user
OUTPUT FORMAT
If auto - completions exists, output all of them in lexicographical order else output "No suggestions" without quotes

NOTE: All strings are lowercase
SAMPLE INPUT
3
fact
factorial
factory
2
fact
pradyumn
SAMPLE OUTPUT
fact
factorial
factory
No suggestions
*/


#include <bits/stdc++.h>
using namespace std;

class Trie{
    public:
    	Trie** children;
    	bool word_end; //to store wether node has any word ending there ex: if words fact,facto present we need to print both fact and facto (if we dont use word_end we only print "facto")
    Trie(){
        children = new Trie*[26];
        for(int i=0;i<26;i++){
            children[i] = NULL;
        }
        word_end = false;
    }
};

void insert(Trie* root,string str){
    if(str.empty()){
        root->word_end = true;   //indicates node has the character which is the last character in word
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
    insert(child,str.substr(1));
    return;
}

//Printing all the strings thar are possible from given prefix using DFS ex: if given string is "do" start DFS after "do" to get all words in trie
void printDFS(Trie* current,string prefix){
    if(current->word_end){  //if word end is reached print word ans start exploring again
        cout << prefix << endl;
    }
    
    for(int i=0;i<26;i++){  //iterating to all possible nodes 
        Trie* temp = current;
        if(temp->children[i]){
            char suffix = (int)i + (int)'a'; //concatenating character to original string
            printDFS(temp->children[i],prefix+suffix); 
        }
    }
}

void query(Trie* root,string prefix){
    Trie* current = root;
    for(int i=0;i<prefix.length();i++){
        int index = prefix[i] - 'a';
        if(current->children[index]){
            current = current->children[index];
        }else{
            cout << "No suggestions" << endl;
            insert(root,prefix);  //given in question if "No suggestions" insert word in words dictionary
            return;
        } 
    }
    
    printDFS(current,prefix);//printing words which all have prefix same as given string
    return;
}


int main()
{
    Trie* root = new Trie();
    int n;
    cin >> n;
    while(n--){
        string str;
        cin >> str;
        insert(root,str);
    }
    int q;
    cin >> q;
    while(q--){
        string str;
        cin >> str;
        query(root,str);
        cout << endl;
    }
    return 0;
}

