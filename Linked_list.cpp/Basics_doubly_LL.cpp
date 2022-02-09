#include<iostream>
using namespace std;
typedef struct node1{
    int data;
    struct node1 *next;
    struct node1 *prev;
}node;

// create doubly linked list
void insert(node *&head,node *&tail,int a)
{
    node *temp=(node *)malloc(sizeof(node ));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}

// Display linked list 
void show(node *&head,node *&tail)
{
    node *temp=head;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// Insert node at start
void insert_node_starting(node *&head,node *&tail,int a)
{
   node *temp=(node *)malloc(sizeof(node ));
   temp->data=a;
   temp->next=NULL;
   temp->prev=NULL;

   temp->next=head;
   head->prev=temp;
   head=temp;
}

// insert node at end
void insert_node_ending(node *&head,node *&tail,int a)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;

    tail->next=temp;
    temp->prev=tail;
    tail=temp;
}

// insert at index
void insert_at_index(node *&head,node *&tail,int a,int idx)
{
    node *temp=(node *)malloc(sizeof(node));
    temp->data=a;
    temp->next=NULL;
    temp->prev=NULL;

    int c=1;
    node *t=head;
    while(c<idx)
    {
       c++;
       t=t->next;
    }
    temp->next=t->next;
    t->next->prev=temp;
    t->next=temp;
    temp->prev=t;
}

// delete  starting node
void delete_at_start(node *&head,node *&tail)
{
    node *temp=head;
    head=head->next;
    head->prev=NULL;
    temp->next=NULL;
}

// delete  ending node
void delete_at_end(node *&head,node *&tail)
{
    node* temp=head;
    while(temp->next->next!=NULL)
    {
        temp=temp->next;
    }

    temp->next=NULL;
    tail->prev=NULL;
    tail=temp;
}

// delete at index
void delete_at_index(node *&head,node *&tail,int idx)
{
    node *t=head;
    int c=1;
    while(c<idx)
    {
        c++;
        t=t->next;
    }
    node *temp=t;
    t->next=t->next->next;
    t=t->next;
    t->prev=temp;
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
    //insert_node_starting(head,tail,0);
    //insert_node_ending(head,tail,6);
    //insert_at_index(head,tail,30,2);
    //delete_at_start(head,tail);
    //delete_at_end(head,tail);
    delete_at_index(head,tail,2);
    show(head,tail);
    return 0;
}