#include<iostream>
using namespace std;
#define n 100// initialise  n's value
class stack{
    int top;
    int *a;// use pointer --> use as array
    public:
    stack()
    {
        top=-1;
        a=new int[n];
    }
    void push(int x)
    {
        if(top==n-1)
        {
            cout<<"stack is full"<<endl;
            return ;
        }
        else
        {
            top++;
            a[top]=x;
        }
    }
    void pop()
    {
        if(top==-1)
        {
            cout<<"stack is empty"<<endl;
            return ;
        }
        else
        {
            top--;
        }
    }
    int Top()
    {
        if(top==-1)
        {
            cout<<"stack is empty "<<endl;
            return -1;

        }
        else
        {
            return a[top];
        }
    }
    bool empty()
    {
     if(top==-1)
     {
         return true;
     }
     else
     {
         return false;
     }
    }
};
int main()
{
    stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();
    cout<<st.Top()<<"\n";
    st.pop();
    cout<<st.Top()<<"\n";
    st.pop();
    cout<<st.Top()<<"\n";
    st.pop();
    cout<<st.Top()<<"\n";
    return 0;
}