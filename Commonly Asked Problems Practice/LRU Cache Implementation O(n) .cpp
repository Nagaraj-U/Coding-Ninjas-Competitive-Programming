#include<bits/stdc++.h>

//LRU algorithm : caching technique in which least recently used process/data is removed once 
//cache is full and when we read/write particular element it becomes most recently used (should be on top of qeueu)
// approach : can be implemented using queue (front element indicates least recently used process)



/*
Problem Statement
Design and implement a data structure for Least Recently Used (LRU) cache to support the following operations:
get(key) - Return the value of the key if the key exists in the cache, otherwise return -1.
put(key, value), Insert the value in the cache if the key is not already present or update the value of the given key if the key is already present. 
When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
Two type of queries denote these operations:
Type 1: for get(key) operation.
Type 2: for put(key, value) operation.
The cache is initialized with a capacity (the maximum number of unique keys it can hold at a time).
Note:
Access to an item or key is defined as a get or a put operation on the key. The least recently used key is the one with the oldest access time.
Input Format:
The first line of input contains two space separated integers C and Q, denoting the capacity of the cache and the number of operations to be performed respectively.

The next Q lines contain operations, one per line. Each operation starts with an integer which represents the type of operation. If it is 0, then it is of first type and 
is followed by one integer key. If it is 1, it is of second type and is followed by two space separated integers key and value(in this order).
The meanings of key and value are well explained in the statement.    
Constraints:
1 <= C <= 10^4
1 <= Q <= 10^5
1 <= key, value <= 10^9

Time Limit: 1 sec
Output Format:
For each operation of type 0, print an integer on a single line - the value of the key if the key exists, otherwise -1.
Sample Input 1:
3 11
1 1 1
1 2 2
1 3 3
1 4 5
0 3
0 1
0 4
1 2 3
0 1
0 3
0 2
Sample Output 1:
3
-1
5
-1
3
3
Explanation To Sample Input 1:

Initializing a cache of capacity 3, LRUCache cache = new LRUCache(3);
Then each operation is performed as shown in the above figure.
cache.put(1,1)
cache.put(2,2)
cache.put(3,3)
cache.put(4,5)
cache.get(3)      // returns 3
cache.get(1)      // returns -1
cache.get(2)      // returns 2
cache.put(5,5)
cache.get(4)      // returns -1
cache.get(3)      // returns 3
Sample Input 2:
2 6
1 1 1
1 2 2
0 2
1 3 3
0 3
0 1
Sample Output 2:
2
3
-1
Pre


*/



class LRUCache {
public:    	
	// Initialize LRUCache 
    unordered_map<int,int> m;
 	int size;
    queue<pair<int,int>> q;  //in given question only think about key , value is no use with logic
	LRUCache(int capacity) {
		// Write your code here
		size = capacity;
    }
	
	// Return the value of the given key
	int get(int key) {
		// Write your code here
        if(m[key] != 0){ //if already present
    		int count = size;
            pair<int,int> ans;
            while(count--){
                pair<int,int> pp = q.front();
                if(pp.first == key){ //get that already present 
                    ans = pp;
                    q.pop();
                    continue;
                }else{
                    q.pop();
                    q.push(pp);
                }
            }
            q.push(ans); //push already present to back , since it used recently (ie get() is used)
            return m[key];
        }else{
            return -1;
        }
	}

	// Inserts a key and it's value into the LRUCache
	void put(int key, int value) {
		// Write your code here
        pair<int,int> p;
        p.first = key;
        p.second = value;
       if(m[key] != 0){ //if already present
    		int count = size;
            pair<int,int> ans;
            while(count--){
                pair<int,int> pp = q.front();
                if(pp.first == key){
                    ans = pp;  //get already present and 
                    q.pop();
                    continue;
                }else{
                    q.pop();
                    q.push(pp); //pushing all elements back except the one that is already present
                }
            }
           m[key] = value;
           q.push(p);
       }else{
           if(q.size() == size){   //remove front element
           pair<int,int> temp = q.front();
           m[temp.first] = 0;
           q.pop();
           m[key] = value;
           q.push(p);
           }else{  //is space available in queue push 
               m[key] = value;
               q.push(p);
           }
       }
        return;
		
	}

};



