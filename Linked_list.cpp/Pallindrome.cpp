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


//helper function
bool helper_pall(node *&left,node *&right)//& ->important 
{
    if(right==NULL)
    {
        return true;
    }
    bool t=helper_pall(left,right->next);
    if(t==false)
    {
        return false;
    }
    else if(t==true && right->data!=left->data)
    {
        return false;
    }
    else
    {
        left=left->next;
        return true;
    }


}
// Pallindrome -----------> SC =O(n)-------->use reverse method -> half list then compare
bool pallindrome(node *&head)
{
    if(head==NULL)return true;
    return helper_pall(head,head);
}

int main()
{
    node *head=NULL,*tail=NULL;
    insert(head,tail,1);
    insert(head,tail,2);
    insert(head,tail,3);
    insert(head,tail,1);
    show(head,tail);
    cout<<"\n";
    cout<<pallindrome(head);
    return 0;
}