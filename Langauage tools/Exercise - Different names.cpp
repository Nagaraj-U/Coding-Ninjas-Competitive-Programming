/*
In Little Flowers Public School, there are many students with same first names. You are given a task to find the students with same names. 
You will be given a string comprising of all the names of students and you have to tell the name and count of those students having same. 
If all the names are unique, print -1 instead.
Note: We don't have to mention names whose frequency is 1.
Input Format:
The only line of input will have a string ‘str’ with space separated first names of students.
Output Format:
Print the names of students along with their count if they are repeating. If no name is repeating, print -1
Constraints:
1 <= |str| <= 10^5
Time Limit: 1 second
Sample Input 1:
Abhishek harshit Ayush harshit Ayush Iti Deepak Ayush Iti
Sample Output 1:
harshit 2
Ayush 3
Iti 2
Sample Input 2:
Abhishek Harshit Ayush Iti
Sample Output:
-1
*/




#include<bits/stdc++.h>
using namespace std;

vector<string> splitString(string s){
    vector<string> result;
    long start = 0;
    long end = 0;
    while(end < s.length()){
        while(s[end] != ' '){
            end++;
        }
        string str = s.substr(start,end-start);
        result.push_back(str);
        end++;
        start = end;
        
    }
    return result;
}

int main(){
    string s;
    getline(cin,s);
    map<string,int> m;
    vector<string> v = splitString(s);
    map<string,int>::iterator it;
    for(int i=0;i<v.size();i++){
        m[v[i]] += 1;
    }
    int count = 0;
    for(it=m.begin();it!=m.end();it++){
        string name = it -> first;
        int freq = it -> second;
        if(freq >= 2){
            cout << name << " " << freq << endl;
            count ++;
        }
    }
    if(count == 0){
        cout << "-1" ;
    }
    return 0;
}
