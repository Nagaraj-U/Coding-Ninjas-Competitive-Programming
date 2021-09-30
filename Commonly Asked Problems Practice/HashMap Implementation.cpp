#include<bits/stdc++.h>
using namespace std;


class HashMap
{
public:
    int bucketSize;
    int count;

    class Node{
    public:
        string key;
        int val;
        Node* next;
        Node(string str,int v){
            this->key = str;
            this->val = v;
            this->next = NULL;
        }
    };

    
    Node** bucket;//bucket array in which each array index is the linked list 
    HashMap(){
        this->bucketSize = 10;
        this->count = 0;
        bucket = new Node*[bucketSize];
        for(int i=0;i<bucketSize;i++){
            bucket[i] = NULL;
        }
    }

    int hash(string key){
        int prime = 1;
        int hashcode = 0;
        for(int i=key.length()-1;i>=0;i--){
            hashcode += (key[i] * prime);
            hashcode %= bucketSize;
            prime *= 37;
            prime %= bucketSize;
        }
        //cout << " hash for " << key << " is " << hashcode % bucketSize << endl;
        return hashcode % bucketSize;
    }

    void insert(string key,int val){
        int bucketIndex = hash(key);
        Node* temp = bucket[bucketIndex];

        while(temp){
            if(temp->key == key){//if already present update it
                temp->val = val;
                return;
            }
            temp = temp->next;
        }

        Node* curr = new Node(key,val);//create new node
        curr->next = bucket[bucketIndex];
        bucket[bucketIndex] = curr;
        count++;

        cout << " inserted " << key << " size " << size() << endl;
        return;
    }

    void erase(string key){
        int bucketIndex = hash(key);
        Node* temp = bucket[bucketIndex];
        Node* prev = NULL;
        while(temp){
            if(temp->key == key){
                if(prev == NULL){
                    bucket[bucketIndex] = temp->next;
                }else{
                    prev->next = temp->next;
                }
                count--;
                cout <<" deleted " << key << " size " << size() << endl;
                return;
            }
            temp = temp->next;
        }

        cout << "key not found" << endl;
        return;
    }

    void getValue(string key){
        int bucketIndex = hash(key);
        Node* temp = bucket[bucketIndex];
        while(temp){
            if(temp->key == key){
                cout << " key " << temp->key << " value " << temp->val << endl;
                return;
            }
            temp = temp->next;
        }
        cout << "key not found " << endl;
        return;
    }

    int size(){
        cout << " size " << count << endl;
        return count;
    }
    
};

int main(){
    HashMap obj;
    obj.insert("abc",1);
    obj.insert("xyz",2);
    obj.erase("abc");
    obj.insert("pqr",6);
    obj.getValue("xyz");
    obj.insert("xyz",3);
    obj.getValue("xyz");
    return 0;
}
