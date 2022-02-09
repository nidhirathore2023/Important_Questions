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

// Merge LL 
node * merge(node *&head1,node *&head2)
{
    node* dummy=(node *)malloc(sizeof(node));
    node *p1=head1;
    node *p2=head2;
    node * p3=dummy;

    while(p1!=NULL && p2!=NULL)
    {
        if(p1->data<p2->data)
        {
            p3->next=p1;
            p1=p1->next;
        }
        else
        {
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL)
    {
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL)
    {
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
}
int main()
{
    node *head1=NULL,*tail1=NULL;
    insert(head1,tail1,1);
    insert(head1,tail1,2);
    insert(head1,tail1,3);
    insert(head1,tail1,45);
    insert(head1,tail1,55);
    insert(head1,tail1,56);
    show(head1,tail1);
    cout<<"\n";
    node *head2=NULL,*tail2=NULL;
    insert(head2,tail2,1);
    insert(head2,tail2,3);
    insert(head2,tail2,40);
    insert(head2,tail2,57);
    insert(head2,tail2,60);
    show(head2,tail2);
    cout<<"\n";
    head1=merge(head1,head2);
    show(head1,tail1);
    return 0;
}