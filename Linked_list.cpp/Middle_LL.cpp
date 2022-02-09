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

// Middle of Linked_list --> one iteration 

/*
Example-> 1 2 3 4 5(odd)
ans=3

Example -> 1 2 3 4 5 6 (even)
ans=3 ->>( it will return first one in middle element )

(To get second element from middle elments fast=head )---> instead of head->next
Example -> 1 2 3 4 5 6 (even)
ans=4 ->>( it will return second one in middle element )

*/
node * middle(node *&head,node *&tail)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node *slow=head;
    node *fast=head->next;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
    } 
    return slow;
}
int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,3);
    insert(head,tail,4);
    insert(head,tail,5);
    insert(head,tail,6);
    show(head,tail);
    cout<<"\n";
    node *temp=middle(head,tail);
    cout<<temp->data;
    return 0;
}