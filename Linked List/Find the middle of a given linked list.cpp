#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};

struct node *addnode(node *head, int num)
{
    if (head == NULL)
    {
        node *temp = new node();
        temp->data = num;
        temp->next = NULL;
        return temp;
    }

    node *newnode = new node();
    newnode->data = num;
    newnode->next = head;
    return newnode;
}

void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    return;
}
int printMiddle(node *head)
{
    node *fast = head;
    node *slow = head;
    while (fast != NULL && fast->next != NULL)
    {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

int main()
{
    node *head = NULL;
    for (int i = 5; i >= 0; i--)
    {
        head = addnode(head, i);
    }
    print(head);
    cout << "middle node is " << endl;
    cout << printMiddle(head) << endl;
    return 0;
}

