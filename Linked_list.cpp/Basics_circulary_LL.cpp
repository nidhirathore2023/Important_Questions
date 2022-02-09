#include<iostream>
using namespace std;
typedef struct node1{ //typedef -> no need to use ----->  struct node1 *head --> instead can use --> node * head 
    int data;
    struct node1 *next;
}node;


// insert
void insert(node *&head,node *& tail,int a)
{
    node *temp=(node *)malloc(sizeof(node ));
    temp->data=a;
    temp->next=temp;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
    }
    else
    {
        tail->next=temp;
        temp->next=head;
        tail=temp;

    }
}

// display linked list
void show(node *& head,node *&tail)
{
    cout<<head->data<<" ";
    node *temp=head->next;
    while(temp!=head)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}

// insert at starting
void insert_node_starting(node *&head,node *&tail,int a)
{
    node *temp=head;
    while(temp->next!=head)
    {
        temp=temp->next;
    }
     
     node *t=(node *)malloc(sizeof(node ));
     t->data=a;
     t->next=NULL;

     temp->next=t;
     t->next=head;
    head=t;
}

// insert at index
void insert_at_index(node *&head,node *&tail,int a,int idx)
{
    node *temp=head;
    int c=1;
    while(c<idx)
    {
        c++;
        temp=temp->next;
    }
    node *t=(node *)malloc(sizeof(node));
    t->data=a;
    t->next=NULL;

    t->next=temp->next;
    temp->next=t;
}

// delete start
void delete_start(node *& head,node *& tail)
{
    node *temp=head;
    while(temp->next!=head)
    {
     temp=temp->next;
    }
    head=head->next;
    temp->next=head;

}

// delete index

void delete_index(node *& head,node*& tail,int idx)
{
    node *temp=head;
    int c=1;
    while(c<idx)
    {
        c++;
        temp=temp->next;
    }
    temp->next=temp->next->next;
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
    //insert_at_index(head,tail,4,2);
    //delete_start(head,tail);
    //delete_index(head,tail,2);
    show(head,tail);
    return 0;
}