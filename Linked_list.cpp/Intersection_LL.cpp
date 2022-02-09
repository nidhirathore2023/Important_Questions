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

//Create Intersection
void create_intersection(node *&head1,node *& tail1,node*head2,node *tail2 )
{
    node *temp=head1;
    temp=temp->next;
    temp=temp->next;
    temp=temp->next;
     
    tail2->next=temp;
}

// length of linked list
int length(node *head)
{
    int c=0;
    node *temp=head;
    while(temp!=NULL)
    {
        c++;
        temp=temp->next;
    }
    return c;
}

// Check Intersection
node *intersection(node *&head1,node *&head2)
{
    int s1=length(head1);
    int s2=length(head2);
    
    node *t1=head1;
    node *t2=head2;
    if(s1>s2)
    {
        int diff=s1-s2;
        while(diff--)
        {
          t1=t1->next;
        }
    }
    else
    {
        int diff=s2-s1;
        while(diff--)
        {
          t2=t2->next;
        }
    }
    while(t1 !=NULL && t2!=NULL)
    {
        if(t1==t2)
        {
            return t1;
        }
        t1=t1->next;
        t2=t2->next;
    }
    return NULL;
}

int main()
{
    node *head1=NULL,*tail1=NULL;
    insert(head1,tail1,1);
    insert(head1,tail1,2);
    insert(head1,tail1,3);
    insert(head1,tail1,4);
    insert(head1,tail1,5);
    show(head1,tail1);
    cout<<"\n";
    node *head2=NULL,*tail2=NULL;
    insert(head2,tail2,10);
    insert(head2,tail2,20);
    insert(head2,tail2,30);
    show(head2,tail2);
    create_intersection(head1,tail1,head2,tail2);
    cout<<"\n";
    show(head1,tail1);
    cout<<"\n";
    show(head2,tail2);
    cout<<"\n";
    node *temp=intersection(head1,head2);
    cout<<temp->data;
    return 0;
}