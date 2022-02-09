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

// Reverse LL iteartively
node * reverse(node *&head,node *&tail)
{
    if(head==NULL)
    {
        return head;
    }
    node *prev=NULL;
    node *curr=head;
    node *next1;
    while(curr!=NULL)
    {

        next1=curr->next;

        curr->next=prev;
        prev=curr;
        curr=next1;
    }
    return prev;

}
int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,3);
    insert(head,tail,4);
    insert(head,tail,5);
    show(head,tail);
    cout<<"\n";
    head=reverse(head,tail);
    show(head,tail);
    return 0;
}