#include<iostream>
#include<vector>
using namespace std;
/*
Push - O(log n)-> upheapify
Pop - O(log n) ->downheapify
Top - minimum value -> O(1)
*/
class Min_heap{

vector<int>a;// array for storing tree

// Upheapify
void upheapify(int child)
{
    if(child==0) // till reach root
    {
        return;
    }
    int parent=(child-1)/2;
    if(a[parent]>a[child]) // compare child and parent 
    {
        int t=a[parent];
        a[parent]=a[child];
        a[child]=t;
        upheapify(parent);
    }
}

// Downheapify
void downheapify(int parent)
{
    int c1=2*parent+1;
    int c2=2*parent+2;
    int mi=parent;

    // Get minimum of both children
    if(c1<a.size() && a[mi] >a[c1])
    {
        mi=c1;
    }
    if(c2<a.size() && a[mi]>a[c2])
    {
        mi=c2;
    }

    if(mi!=parent) // if get minimum other than parent --> Swap and call downheapify
    {
        int temp=a[mi];
        a[mi]=a[parent];
        a[parent]=temp;
        downheapify(mi);
    }
}

public:

// Push --->
// 1- Push value in vector
// 2-Call upheapify
void push(int val)
{
    a.push_back(val);
    upheapify(a.size()-1);
}


// Pop
// 1- Swap first and last element ---> to make pop()-> O(1)
//2 - Pop last value
//3 - call downheapify
void pop()
{
    int temp=a[0];
    a[0]=a[a.size()-1];
    a[a.size()-1]=temp;
    a.pop_back();
    downheapify(0);
}

// Return minimum value
int top()
{
   return a[0];
}



};
int main()
{
    Min_heap m;
    m.push(10);
    m.push(2);
    m.push(10);
    m.push(-15);
    m.push(36);
    m.push(-7);
    cout<<m.top()<<" ";
    m.pop();
    cout<<m.top()<<" ";
    return 0;
}


