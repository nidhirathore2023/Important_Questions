#include<iostream>
using namespace std;
typedef struct node1{ //typedef -> no need to use ----->  struct node1 *head --> instead can use --> node * head 
    int data;
    struct node1 *next;
}node;

//insert values

void insert(node *& head,node *&tail ,int a)// pass value by reference -- > no extra space and head is update otherwise it's copy will be updated
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

// add node at starting 

void add_node_starting(node * &head,node*& tail,int a)
{
     node *temp=(node *)malloc(sizeof(node));
     temp->data=a;
     temp->next=head;
     head=temp;
}

// add  node at ending

void add_node_ending(node * &head,node*& tail,int a)
{
     node *temp=(node *)malloc(sizeof(node));
     temp->data=a;
     tail->next=temp;
     tail=temp;
}

// add node at given index

void add_node_at_index(node * &head,node*& tail,int a,int idx)
{
     node *t=head;
     int c=1;
     while(c<idx)
     {
        t=t->next;
        c++;
     }
     node *temp=(node *)malloc(sizeof(node));
     temp->data=a;
     temp->next=t->next;
     t->next=temp;
}

//delete starting node
void delete_start(node * &head,node*& tail)
{
    node *t=head;
    head=head->next;
    t->next=NULL;
}

// delete ending node
void delete_end(node * &head,node*& tail)
{
    node *t=head;
    while(t->next->next!=NULL)
    {
        t=t->next;
    }
    t->next=NULL;
    tail=t;
}

//delete node at index
void delete_at_index(node * &head,node*& tail,int idx)
{
   int c=1;
   node*t=head;
   while(c<idx)
   {
    c++;
    t=t->next;
   }
   t->next=t->next->next;
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
   // add_node_starting(head,tail,0);
   // add_node_ending(head,tail,6);
   // add_node_at_index(head,tail,13,3);
   //delete_start(head,tail);
   //delete_end(head,tail);
   //delete_at_index(head,tail,3);
    show(head,tail);
    return 0;
}