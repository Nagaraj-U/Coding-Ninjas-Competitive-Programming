/*
Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
int get(int key) Return the value of the key if the key exists, otherwise return -1.
void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
If the number of keys exceeds the capacity from this operation, evict the least recently used key.
The functions get and put must each run in O(1) average time complexity.

 

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4
 

Constraints:

1 <= capacity <= 3000
0 <= key <= 104
0 <= value <= 105
At most 2 * 105 calls will be made to get and put.
*/




//least recently used process is always present at back of list

class LRUCache {
public:
    
    class node{
        public:
        int val;
        int key; //storing key also , since while deleting last recently used , node is also need to delete from map for which key is required
        node* prev;
        node* next;
        node(int key_,int val_){
            val = val_;
            key = key_;
            prev = NULL;
            next = NULL;
        }
    };
    
    //adding head and tail dummy nodes to avoid list becoming empty and handling nnull values
    int size;
    node* head;
    node* tail;
    unordered_map<int,node*> m;
    
    LRUCache(int capacity) {
         head = new node(-1,-1);
         tail = new node(-1,-1);
         head->next = tail;
         tail->prev = head;
         size = capacity;
    }
    
    void addnode(int key,int val){ //adding node always at begin (after dummy head node)
        node* newnode = new node(key,val);
        node* temp = head->next;
        newnode->prev = head;
        newnode->next = temp;
        head->next = newnode;
        temp->prev = newnode;
        return;
    }
    
    void deletenode(node* temp){ //delete the current node
        node* nextnode = temp->next;
        node* prevnode = temp->prev;
        prevnode->next = nextnode;
        nextnode->prev = prevnode;
        return;
    }
    
    int get(int key) {
        if(m.count(key) != 0){ //if already exist , remove it and add it to begin
            node* current = m[key];
            int value = current->val;
            deletenode(m[key]);
            m.erase(key);
            addnode(key,value);
            m[key] = head->next;
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(m.count(key) != 0){//already exist
            deletenode(m[key]);//delete the old one and create new node and add to begin
            m.erase(key);//also delete from map , since new node is created, hence value changes
            addnode(key,value);
            m[key] = head->next;//new node is added at begin , hence its address in head->next
        }else{
            if(m.size() == size){//size reached
                m.erase(tail->prev->key);//delete last node
                deletenode(tail->prev);//follow same order
                addnode(key,value);//add current node to begin
                m[key] = head->next;//new node added to map
            }else{
                addnode(key,value);//space exist , simply add
                m[key] = head->next;
            }
        }
        return;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
