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

node * merge(node * head1,node *head2)
{
    node * dummy=(node *)malloc(sizeof(node));
    node *p3=dummy;
    node *p1=head1;
    node *p2=head2;

    while(p1 && p2)
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
    if(p1)// ------------> different way to append rest of linked list
    {
        p3->next=p1;
    }
    if(p2)// ------------> different way to append rest of linked list
    {
        p3->next=p2;
    }
    return dummy->next;
}
//Merge Sort
node * merger_sort(node *&head)
{
   if(head==NULL || head->next==NULL)
   {
       return head;
   }
   node* slow=head;
   node *fast=head->next;
   while(fast!=NULL && fast->next!=NULL)// find middle of linked list
   {
       fast=fast->next->next;
       slow=slow->next;
   }

   node *head1=slow->next;// divide linked list in to parts
   slow->next=NULL;
   node *head2=head;

   return merge(merger_sort(head1),merger_sort(head2));// till head!=NULL OR head->next!=NULL----> call merge function merge list in sorted form 

}
int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,36);
    insert(head,tail,39);
    insert(head,tail,4);
    insert(head,tail,-1);
    show(head,tail);
    cout<<"\n";
    head=merger_sort(head);
    show(head,tail);
    return 0;
}