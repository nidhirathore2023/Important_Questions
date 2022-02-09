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

// Create cycle
void create_cycle(node *&head)
{
    node* temp=head;
    node *start;
    int c=0;
    while(temp->next!=NULL)
    {
        if(c==3)
        { 
            start=temp;
        }
        c++;
        temp=temp->next;
    }
    
    temp->next=start;
}

// Check cycle--------------------------------> Hare and Tortise Algorithm (Flyod's Algorithm )
bool is_cycle(node *&head)
{
    if(head==NULL || head->next ==NULL)
    {
       return false;
    }
    node *slow=head;
    node *fast=head;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
        {
            return true;
        }
    }
  return false;
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
    create_cycle(head);
    cout<<is_cycle(head);
   // show(head,tail);
    return 0;
}