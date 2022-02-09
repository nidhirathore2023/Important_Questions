#include<iostream>
using namespace std;
typedef struct node1{ 
    int data;
    struct node1 *next;
}node;

//insert values

void insert(node *& head,node *&tail ,int a)
{
    node *temp=(node *)malloc(sizeof(node));// malloc for memory allcoation by default it's retuen type is void --> ( need to typecast it )
    temp->data=a;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }
}

// display result
void show(node * &head,node*& tail)// here taking head by value will also work ->  since no changes are needed here
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Remove Duplicetes
node * remove_duplicate(node *head)
{
    node *temp=head;
    while(temp!=NULL && temp->next!=NULL)
    {
        if(temp->data==temp->next->data)// skip dupliacte if found
        {
           temp->next=temp->next->next;
        }
        else// else continue;
        {
            temp=temp->next;
        }
    }
    return head;
}

int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,2);
    insert(head,tail,5);
    insert(head,tail,5);
    show(head,tail);
    cout<<"\n";
    head=remove_duplicate(head);
    show(head,tail);
    return 0;
}