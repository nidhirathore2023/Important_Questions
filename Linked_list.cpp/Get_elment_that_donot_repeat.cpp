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

// No Duplicates
node * no_duplicates(node *&head)
{
    if(head ==NULL || head->next==NULL)
    {
        return head;
    }
    node *dummy=(node *)malloc(sizeof(node));
    node *p=dummy;
    node *curr=head;
    while(curr!=NULL)// iterate over complete linked list
    {
        if( curr->next!=NULL && curr->data == curr->next->data)// if next node existed and current and next node have same value
        {
            int val=curr->data;
           while(curr!=NULL && curr->data==val )// then simpliy increase curr till next value is different from current value 
           {
             curr=curr->next;
           }
        }
        else// iif current value if differnt from next value then add ----> Current  value ( next value will be checked in next iteration ex- 1 3 3 3 -> here only current is added) rest  will treated in next iteration   
        {
            p->next=curr;
            p=p->next;
            curr=curr->next;
        }
    }
    p->next=NULL;//------------->Important --> edge case =>  1 2 2  --> link between 1 and 2 needs to be broken
    return dummy->next;
}

int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,2);
    insert(head,tail,5);
    insert(head,tail,6);
    show(head,tail);
    cout<<"\n";
    head=no_duplicates(head);
    show(head,tail);
    return 0;
}