#include<iostream>
using namespace std;

class Node
{
public :
    int data;
    Node* next;

    Node(int v)
    {
        data=v;
        next=NULL;
    }

};

void insertAtHead(Node* &head, int x)
{
    Node* newNode=new Node(x);
    newNode->next=head;
    head=newNode;
}

void insertAtTail(Node* &head, int x)
{
    Node* newNode=new Node(x);
    Node* temp=head;
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(Node* head)
{
    Node* temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* removeGhartera(Node* &head)
{
    if(head==NULL) return NULL;
    Node* temp = head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)
        {
            Node* dhutbat=temp->next;
            temp->next=dhutbat->next;
            delete dhutbat;
        }
        else temp = temp->next;
    }
    return head;
}

int main()
{
    Node* n=NULL;
    int s;
    cout<<"Enter size : ";
    cin>>s;
    for(int i=1; i<=s; i++)
    {
        int x;
        cin>>x;
        if(i==1)
        insertAtHead(n,x);
        else insertAtTail(n,x);
    }
    cout<<"Linked list : ";
    display(n);
    cout<<"After removing duplicates : ";
    Node* m=removeGhartera(n);
    display(m);
    return 0;
}
