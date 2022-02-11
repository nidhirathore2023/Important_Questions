#include<iostream>
#include<stack>
using namespace std;
/* Get Minimum value in stack in O(n) time ---> using two stacks S.C =O(n)
*/
class min_stack{
stack<int>all_data;// all data in stack (original stack)
stack<int>min_data;// stack having minimum values 

public:
void push(int a)
{
    if(min_data.empty()||a<=min_data.top())// if min stack is Empty Or current value is smaller than min top then ---> push to both stacks
    {
        all_data.push(a);
        min_data.push(a);
    }
    else// ----> push only to all data
    {
        all_data.push(a);
    }
}
void pop()
{
    if(!all_data.empty())
    {
        if(all_data.top()==min_data.top())// if---> top of both stacks are equal than pop both
        {
            all_data.pop();
            min_data.pop();
        }
        else // only all data stack
        {
            all_data.pop();
        }
    }
}
bool empty()
{
    if(all_data.empty())
    return 0;
    else 
    return 1;
}
int min_el()
{
    return min_data.top();// top of minimum stack  give minimum value in constant time
}
};
int main()
{
    min_stack st;
    st.push(32);
    st.push(20);
    st.push(100);
    st.push(-4);
    st.push(48);
    cout<<st.min_el()<<" ";
    st.pop();
    st.pop();
    cout<<st.min_el()<<" ";
    return 0;
}