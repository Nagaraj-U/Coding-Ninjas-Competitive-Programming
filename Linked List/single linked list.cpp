
#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
};

void print(Node* head)
{
    Node* temp = head;
    while(temp != NULL)   
    {   
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void insertAtBegin(Node** head,int data) //pointer to pointer for head coz need to change value (pas by reference)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = (*head);
    (*head) = new_node;
    return;
}

void insertAfter(Node* prev,int data)
{
    if(prev == NULL){
        cout << " previous node cannot be null" << endl;
    }

    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = prev->next;
    prev->next = new_node;
    return;
}

void insertAtEnd(Node** head,int data)
{
    Node* new_node = new Node();
    new_node->data = data;
    new_node->next = NULL;
    Node* temp = *head;

    if(temp == NULL)
    {
        *head = new_node;
        return;
    }

    while(temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void deletenode(Node** head,int key)
{
    Node* temp = *head;
    Node* prev = NULL;
    //if head node contain key to be deleted
    if(temp != NULL && temp->data == key){
        *head = temp->next;
        delete temp;
        return;
    }

    while(temp != NULL && temp->data != key){
        prev = temp;
        temp = temp->next;
    }

    //if key not present in list
    if(temp == NULL){
        cout <<" invalid node data" << endl;
        return;
    }
    prev->next = temp->next;
    delete temp;
    return;
    
}

int main()
{
    Node* head = NULL;
    insertAtBegin(&head,10);
    print(head);
    insertAtBegin(&head,20);
    print(head);
    insertAtEnd(&head,40);
    print(head); 
    insertAfter(head->next,50);//insert at third position
    print(head);
    insertAfter(head->next->next,60);//insert at fourth position
    print(head);
    deletenode(&head,20);
    print(head);
    deletenode(&head,50);
    print(head);
    return 0;
}

/*
10 -> 
20 -> 10 ->
20 -> 10 -> 40 ->
20 -> 10 -> 50 -> 40 ->
20 -> 10 -> 50 -> 60 -> 40 -> 
10 -> 50 -> 60 -> 40 ->
10 -> 60 -> 40 -> 
*/
