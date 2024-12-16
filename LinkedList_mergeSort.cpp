/*  ARIFUL__HRIDOY
--  Given an unsorted linked list.
--  Need to sort by using mergeSort algorithm.
*/

#include<iostream>
using namespace std;

class Node
{
public:
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
    if(head==NULL)
    {
        head=newNode;
        return;
    }
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

Node* findMid(Node* &head)
{
    Node* slow=head;
    Node* fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

Node* LLmerge(Node* &first, Node* &second)
{
    if(first==NULL) return second;
    if(second==NULL) return first;

    Node* mergedHead=NULL;
    Node* temp=NULL;

    if(first->data <= second->data)
    {
        mergedHead=first;
        first=first->next;
    }
    else
    {
        mergedHead=second;
        second=second->next;
    }
    temp=mergedHead;

    while(first!=NULL && second!=NULL)
    {
        if(first->data <= second->data)
        {
            temp->next=first;
            first=first->next;
        }
        else
        {
            temp->next=second;
            second=second->next;
        }
        temp=temp->next;
    }

    if(first!=NULL) temp->next=first;
    else temp->next=second;

    return mergedHead;
}

Node* LLmergeSort(Node* &head)
{
   if(head==NULL || head->next==NULL) return head;

   Node* mid=findMid(head);
   Node* left=head;
   Node* right=mid->next;
   mid->next=NULL;

   left=LLmergeSort(left);
   right=LLmergeSort(right);

   Node* ans=LLmerge(left,right);
   return ans;
}

int main()
{
    Node* n=NULL;
    int s;

    cout<<"Enter size of list: ";
    cin>>s;
    for(int i=1; i<=s; i++)
    {
        int x;
        cin>>x;
        if(i==1) insertAtHead(n,x);
        else insertAtTail(n,x);
    }

    cout<<"Before sort, list: ";
    display(n);

    Node* ans=LLmergeSort(n);
    cout<<"Merged sorted list: ";
    display(ans);

    return 0;
}
