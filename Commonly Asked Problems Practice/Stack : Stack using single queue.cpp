//stack implementation using single queue 

#include<bits/stdc++.h>
using namespace std;
queue<int> q;

void size()
{
    cout << "size " << q.size() << endl;
    return;
}

void peek()
{
    cout << "top " << q.front() << endl;
    return;
}

void push(int key) //making push operation costly
{
    cout << "pushed" << endl;
    if(q.empty()){
        q.push(key);
        return;
    }
    int n = q.size();
    q.push(key);
    while(n--){ //prev queue elements are pushed back again , so that current element is always at front 
        q.push(q.front());
        q.pop();
    }

    size();
}

void pop()
{
    if(q.empty()){
        cout << "empty stack" << endl;
        return;
    }

    q.pop();
    cout << "popped" << endl;
    return;

}

void display()
{
    if(q.empty()){
        cout << "stack empty" << endl;
        return;
    }
    cout << "display " << endl;
    int n = q.size();
    while(n--){
        cout << q.front() << endl;
        q.push(q.front());
        q.pop();
    }
}



int main()
{
    push(1);
    peek();
    push(2);
    peek();
    pop();
    pop();
    push(5);
    display();
    size();
    return 0;

}

