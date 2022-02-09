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

// Create cycle
void create_cycle(node *&head)
{
    

    node* temp=head;
    node *start;
    int c=0;
    while(temp->next!=NULL)
    {
        if(c==2)
        { 
            start=temp;
        }
        c++;
        temp=temp->next;
    }
    
    temp->next=start;
}

// check cycle
node * find_cycle(node *&head)
{
    if(head==NULL || head->next ==NULL)
    {
       return NULL;
    }
    node *slow=head;
    node *fast=head;//-------------------------> both slow and fast are initailize with head
    int c=0;
    while(fast!=NULL && fast->next!=NULL)
    {
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)//------------>if  they reach at same node ----------> cycle found 
        {
            c=1;
            break;;
        }
    }
  if(c==0)
  {
      return NULL;
  }
  else
  {
      fast=head;
      while(fast!=slow)// reset fast and move both fast and slow till reach -------> at same node 
      {
          fast=fast->next;
          slow=slow->next;
      }
      return fast;// --------> node where cycle exist from last index to index that is being found
  }
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
    create_cycle(head);
    node *temp=find_cycle(head);
    cout<<temp->data;
   // show(head,tail);
    return 0;
}