#include<iostream>
#include<queue>
using namespace std;
#define  n 20
class queue_class{
int front;
int rear;
int *a;

public:
 queue_class()
 {
     front=-1;
     rear=-1;
     a=new int[n];
 }

void push(int val)
{
    if(rear==n-1)
    {
        cout<<"queue is full \n";
    }
   else
   {
       rear++;
       a[rear]=val;
   }
   if(front==-1)
   {
       front++;
   }
}

void pop()
{
    if(front ==-1 || front>rear )
    {
        cout<<"queue is empty \n";
    }
    else
    {
        front++;
    }
}
int front_val()
{
    if(front == rear || front > rear)
    {
        cout<<"queue is empty ";
        return -1;
    }
    return a[front];
}

bool empty()
{
    if(front==rear)
    {
        return true;
    }
    else
    {
        return false;
    }
}

};
int  main()
{
    queue_class q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    cout<<q.front_val()<<" ";
    q.pop();
    cout<<q.front_val()<<" ";
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();
    cout<<q.front_val()<<" ";
    return 0;
}