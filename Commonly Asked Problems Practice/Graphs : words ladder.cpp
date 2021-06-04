/*

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return the number of words in the shortest transformation sequence
from beginWord to endWord, or 0 if no such sequence exists.

 

Example 1:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log","cog"]
Output: 5
Explanation: One shortest transformation sequence is "hit" -> "hot" -> "dot" -> "dog" -> cog", which is 5 words long.
Example 2:

Input: beginWord = "hit", endWord = "cog", wordList = ["hot","dot","dog","lot","log"]
Output: 0
Explanation: The endWord "cog" is not in wordList, therefore there is no valid transformation sequence.
 

Constraints:

1 <= beginWord.length <= 10
endWord.length == beginWord.length
1 <= wordList.length <= 5000
wordList[i].length == beginWord.length
beginWord, endWord, and wordList[i] consist of lowercase English letters.
beginWord != endWord
All the words in wordList are unique.
*/

//since its shortest path applyy BFS

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> s;
      
        for(int i=0;i<wordList.size();i++){
            s.insert(wordList[i]);
        }
        
        if(s.find(endWord) == s.end()){
            return 0;
        }
        
        queue<string> q;
        q.push(beginWord);
        int depth = 0;
        
        while(!q.empty()){
            
            depth += 1;
            int size = q.size();
            while(size--){//explore all words in particular level
                string current = q.front();
                q.pop();
                for(int i=0;i<current.length();i++){
                    for(char c='a';c<='z';c++){ //try changing each index in cuurent word from a to z 
                        string temp = current;
                        if(temp[i] == c){ //current char same as changing one
                            continue;
                        }
                        temp[i] = c;
                        if(s.find(temp) != s.end() && temp == endWord){ //found word , return depth
                            return depth+1;
                        }else if(s.find(temp) != s.end()){
                            q.push(temp);
                            s.erase(temp);//each word can be used only once
                        }
                    }
                }
            }
            
            
        }
        
        return 0;
    }
};
