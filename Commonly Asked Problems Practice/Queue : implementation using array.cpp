


#include<iostream>
using namespace std;
#define size 5
int count = 0;
int front;
int rear;
int arr[size];

void push(int data){
    if(count == size){
        cout << "overflow" << endl;
        return;
    }
    arr[rear++] = data;
    rear = rear % size;
    count++;
    cout << "pushed " << count << endl;
    return;
}

void pop()
{
    if(count == 0){
        cout << "underflow" << endl;
        return;
    }
    front++;
    front = front % size;
    count--;
    cout << "popped " << count << endl;
    return;
}

void display()
{
    if(count == 0){
        cout << "underflow" << endl;
        return;
    }
    cout << "display" << endl;
    int idx = front;
    
    for(int i=0;i<count;i++){
        cout << arr[idx] <<  " ";
        idx++;
        idx = (idx) % size; 
    }
    cout << endl;
    return;
}

void top()
{
    if(count == 0){
        cout << "underflow" << endl;
        return;
    }
    cout << "top " <<  arr[front] << endl;
}


int main()
{
    

    push(1);
    push(2);
    push(3);
    push(4);
    top();
    push(5);
    push(6);
    pop();
    display();
    push(7);
    pop();
    top();
    display();
    return 0;
}



output

pushed 1
pushed 2
pushed 3
pushed 4
top 1
pushed 5
overflow
popped 4
display
2 3 4 5
pushed 5
popped 4
top 3
display
3 4 5 7
