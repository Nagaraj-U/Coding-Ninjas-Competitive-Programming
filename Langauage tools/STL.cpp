// STL (STANDARD TEMPLATE LANGUAGE) WHICH IS A LIBRARY WHICH CONTAINS PRE-BUILT FUNCTIONS
/*
    vector : dynamic array (alternative to array)
    strings ,
*/

#include<iostream>
#include<vector>
#include<string>
#include<utility>
#include<set>
#include<map>



using namespace std;
int main(){
    

    

    //VECTOR WITH SIZE INITIALIZED
    vector<int> v(5); 
    vector<int>::iterator it;
    for(int i=0;i<v.size();i++){
        v[i] = i+1;
    }
    for(it=v.begin();it!=v.end();it++){
        cout << *it << " ";
    }

    //VECTOR WITHOUT SIZE INITIALIZATION
    vector<int> v;
    vector<int>::iterator it;
    for(int i=0;i<5;i++){
       v.push_back(i+1);
    }
    for(it=v.begin();it!=v.end();it++){
        cout << *it << " ";
    }
    




   //STRING
   string s = "nagaraj";
   string s1(s);  //copy s to s1
   string s2(s,2,4);
   string s3 = s.substr(1,4);
   cout << s << " " << s1 << " " << s2 << " " << s3 << endl;;

   if(s1.compare(s1) == 0){
       cout << "strings are equal" << endl;
   }else{
       cout << "strings are not equal " << endl;
   }
   
   
   

   //PAIR
   pair<int,char> p;
   p = make_pair(1,'a');
   cout << p.first << " " << p.second << endl ;

   pair<int,int> p1(1,2);
   cout << p1.first << " " << p1.second << endl;
   

  



  //set is implemented in c++ with balanced binary search tree hence insertion,deletion,searching takes (log n) time
  set<int> s;
  set<int>::iterator it;
  int arr[] = {1,2,3,4,4,5,6,7,8};
  for(int i=0;i<9;i++){
      s.insert(arr[i]);
  }

  for(it=s.begin();it!=s.end();it++){
      cout << *it << " ";
  }

  if(s.find(9) == s.end()){
      cout << "element not found" << endl;
  }else{
      cout << "element found" << endl;
  }
  


 //MAP : implemented using binary each tree where operations take (log n) time
 map<int,int> m;
 map<int,int>::iterator it;
 int arr[] = {1,2,3,4,5,5,6,7};
 for(int i=0;i<8;i++){
     m[arr[i]] = m[arr[i]]+1;
 }

 for(it=m.begin();it!=m.end();it++){
     cout << it->first << " : " << it->second << endl;
 }
 

 //UNORDERED MAP : implemented with hash table where opeartions take o(1) constant time in avg case and o(n) in avg case

 

 return 0;

}
