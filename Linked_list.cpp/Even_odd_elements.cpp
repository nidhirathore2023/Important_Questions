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

// Even odd element 
/*Example- 2 8 9 1 5 4 3 
           9 1 5 3 2 8 4 (based on values)*/

node * even_odd(node *&head)
{
    if(head==NULL || head->next==NULL)
    {
        return head;
    }
    node * even_start=NULL,*even_end=NULL;
    node * odd_start=NULL,*odd_end=NULL;
    node *temp=head;

    while(temp!=NULL)
    {
        int a=temp->data;
        if(a%2==0)
        {
            if(even_start==NULL)
            {
                even_start=temp;
                even_end=temp;
            }
            else
            {
                even_end->next=temp;
                even_end=even_end->next;
            }
        }
        else
        {
            if(odd_start==NULL)
            {
                odd_start=temp;
                odd_end=temp;
            }
            else
            {
                odd_end->next=temp;
                odd_end=odd_end->next;
            }
        }
        temp=temp->next;
    }
    if( even_start==NULL || odd_start ==NULL )
    {
        return head;
    }
    odd_end=NULL;
    even_end->next=odd_start;
    return even_start;
}

int main()
{
    // not working 
    node *head=NULL,*tail=NULL;
    insert(head,tail,2);
    insert(head,tail,8);
    insert(head,tail,9);
    insert(head,tail,1);
    insert(head,tail,5);
    insert(head,tail,4);
    insert(head,tail,3);
    insert(head,tail,11);
    show(head,tail);
    cout<<"\n";
    head=even_odd(head);
    show(head,tail);
    return 0;
}