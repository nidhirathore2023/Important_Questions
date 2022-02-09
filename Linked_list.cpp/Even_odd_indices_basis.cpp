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

// Even odd --------------> (indices Basis) 
/*
example -
2 1 3 5 6 4 7 
2 3 6 7 1 5 4 (not even _ odd values)
*/
node * even_odd(node *&head)
{
    if(head==NULL || head->next==NULL)
     {
         return head;
     }
     node *odd=head;
     node * even=head->next;
     node *even_start=head->next;
     while(odd->next!=NULL && even->next!=NULL)//--------> check first for odd because ---> if we have even elements -> problem 
     {          // this will run for both solution
         odd->next=odd->next->next;
         even->next=even->next->next;
         odd=odd->next;
         even=even->next;
     }
     odd->next=even_start;
     return head;
}
int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,2);
    insert(head,tail,1);
    insert(head,tail,3);
    insert(head,tail,5);
    insert(head,tail,6);
    insert(head,tail,4);
    insert(head,tail,7);
    show(head,tail);
    cout<<"\n";
    head=even_odd(head);
    show(head,tail);
    return 0;
}