/*
priority queue : min heap implementation

implementing using arrays which behaves as tree

heap datastructure :
conditions : 
    -> complete binary tree (diff between left and right tree is atmost 1)
    -> root element is always lesser than both of its childs

index 0 1 2 3 4 5
array 1,2,3,4,5,6

childs of i are 2*i + 1 and 2*i + 2
example : child of 2 are at index 3 and 4 (which are 4,5)

parent of i is calculated by childindex-1/2 
*/

#include<bits/stdc++.h>
using namespace std;
vector<int> pq;

int getMin(){
    if(pq.size() == 0){
        return -1;
    }
    return pq[0];
}


int getSize(){
    return pq.size();
}


void insert(int element){
    pq.push_back(element);//push element at last

    int childIndex = pq.size()-1;

    while(childIndex > 0){
        int parentIndex = (childIndex - 1)/2;
        if(pq[parentIndex] > pq[childIndex]){//if parent has greater value then swap it
            swap(pq[parentIndex],pq[childIndex]);
        }else{
            break;
        }
        childIndex = parentIndex;
    }
    return;
}


void deleteMin(){

    swap(pq[0],pq[pq.size()-1]);//move min element to last and delete it
    pq.pop_back();

    int parentIndex = 0;//from top start checking
    while(parentIndex < pq.size()){

        int minValue = INT_MAX;
        int minIndex = -1;

        int leftChildIndex = 2*parentIndex + 1;
        int rightChildIndex = 2*parentIndex + 2;

        //make sure leftChildIndex and rightChildIndex are within range
        if(leftChildIndex < pq.size() and pq[parentIndex] > pq[leftChildIndex]){
            minValue = pq[leftChildIndex];
            minIndex = leftChildIndex;
        }

        if(rightChildIndex < pq.size() and pq[parentIndex] > pq[rightChildIndex]){
            if(pq[rightChildIndex] < minValue){
                minValue = pq[rightChildIndex];
                minIndex = rightChildIndex;
            }
        }

        if(minIndex != -1){
            swap(pq[parentIndex],pq[minIndex]);
            parentIndex = minIndex;
        }else{
            break;
        }
    }
    
}

int main()
{

    while(1){
        cout << "1 : insert \n 2 : delete \n 3 : size \n 4 : get min \n 5 : exit"<< endl;
        int ch;
        cout << "enter choice" << endl;
        cin >> ch;

        switch(ch){
            case 1 : cout << "enter number to insert" << endl;
                     int element; 
                     cin >> element;
                     insert(element);
                     break;

            case 2 : deleteMin();
                     break;

            case 3 : cout << "size " << getSize() << endl;
                     break;

            case 4 : cout << "min " << getMin() << endl;
                     break;
            case 5 : return 0;
        }
    }
    

    return 0;
}
