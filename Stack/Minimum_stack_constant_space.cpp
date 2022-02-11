#include<iostream>
#include<stack>
using namespace std;
/* Minimum of stack in O(1) time and space  */
class min_stack{
stack<int>orginal_stack;// original stack
int mi;// minimum value 

public:

void push(int val)
{
    if(orginal_stack.empty())// if stack is empty push value and assign mi = value
    {
        mi=val;
        orginal_stack.push(val);
    }
    else if(mi<=val)// if value to be push is greater than the min value the push to stack
    {
        orginal_stack.push(val);
    }
    else  //---------> if value is smaller than mi value the encrypt the value and update min value
    {
        int temp=val+val-mi;// encrypt value 
        orginal_stack.push(temp);
        mi=val;// original value in mi
    }
}
void pop()
{
    if(orginal_stack.top()>mi)// if min is smaller than top value at stack --> then pop value
    {
        orginal_stack.pop();
    }
    else 
    {
        mi=2*mi-orginal_stack.top();// else---> decrpt the value to original value and update mi value accordingly 
        orginal_stack.pop();
    }
}

int min_el()
{
    return mi;// return value of mi
}

int top()
{
    return orginal_stack.top();
}

bool empty()
{
    return orginal_stack.empty();
}

};
int main()
{
    min_stack st;
    st.push(8);
    st.push(40);
    st.push(17);
    st.push(7);
    st.push(13);
    st.push(2);
    cout<<st.min_el()<<" ";
    st.pop();
    cout<<st.min_el()<<" ";
    return 0;
}