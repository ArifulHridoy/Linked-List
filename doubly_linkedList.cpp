/* 2207051
--ARIFUL ISLAM SHEIKH

A program which performs the following operations:

insert x: insert an element with key x into the front of the list.
delete x: delete the first element which has the key of x from the list. If there is not such element, you need not do anything.
deleteFirst: delete the first element from the list.
deleteLast: delete the last element from the list.
*/

#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int val;
    Node* prev;
    Node* next;
    Node(int v)
    {
        val=v;
        prev=nullptr;
        next=nullptr;
    }
};
class DoublyLinkedList
{
private:
    Node* head;
    Node* tail;
public:
    DoublyLinkedList()
    {
        head=nullptr;
        tail=nullptr;
    }

    void Insert(int x)
    {
        Node* newNode=new Node(x);
        if(head==nullptr) head=tail=newNode;
        else
        {
            newNode->next=head;
            head->prev=newNode;
            head=newNode;
        }
    }

    void deleteVal(int x)
    {
        Node* temp=head;
        while(temp)
        {
            if(temp->val==x)
            {
                if(temp==head)
                {
                    head=temp->next;
                if(head) head->prev=nullptr;
                }
                else if(temp==tail)
                {
                    tail=temp->prev;
                    if(tail) tail->next=nullptr;
                }
                else
                {
                    temp->prev->next=temp->next;
                    temp->next->prev=temp->prev;
                }
                delete temp;
                return;
            }
            temp=temp->next;
        }

    }

    void deleteFirst()
    {
        if(head)
        {
            Node* temp=head;
            head=head->next;
            if(head) head->prev=nullptr;
            else tail=nullptr;
            delete temp;
        }
    }

    void deleteLast()
    {
        if(tail)
        {
            Node* temp=tail;
            tail=tail->prev;
            if(tail) tail->next=nullptr;
            else head=nullptr;
            delete temp;
        }
    }

    void printLL()
    {
        Node* temp=head;
        bool first=true;
        while(temp)
        {
            if(!first) cout<<" ";
            cout<<temp->val;
            first=false;
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main()
{
    ios::sync_with_stdio(false);
    int n; cin>>n;
    DoublyLinkedList dll;
    while(n--)
    {
        string cmd; cin>>cmd;
        if(cmd=="insert")
        {
            int x; cin>>x;
            dll.Insert(x);
        }
        else if(cmd=="delete")
        {
            int x; cin>>x;
            dll.deleteVal(x);
        }
        else if(cmd=="deleteFirst")
        {
            dll.deleteFirst();
        }
        else if(cmd=="deleteLast")
        {
            dll.deleteLast();
        }
    }
    dll.printLL();
    return 0;
}


