#include<iostream>
#include<queue>
using namespace std;
class queue_median{
  priority_queue<int,vector<int>>left; // Max heap
  priority_queue<int,vector<int>,greater<int>>right; // Min heap

  public:
  void push(int val)
  {
     if(right.size()>0 && right.top()<val)
     {
       right.push(val);
     }
     else
     {
       left.push(val);
     }
     if(right.size()-left.size()==2)
     {
       int temp=right.top();
       right.pop();
       left.push(temp);
     }
     else if(left.size()-right.size()==2)
     {
       int temp=left.top();
       left.pop();
       right.push(temp);
     }
  }
  void pop()
  {
    if(left.size()>=right.size())
    {
      left.pop();
    }
    else
    {
      right.pop();
    }
  }
  
  int size()
  {
    return (left.size()+right.size());
  }

  int top()
  {
   if(left.size()>=right.size())
    {
      return left.top();
    }
    else
    {
      return right.top();
    }
  }
};
int main()
{
  queue_median q;
  q.push(10);
  q.push(20);
  cout<<q.top()<<" ";
  q.push(30);
  cout<<q.top()<<" ";
  q.push(40);
  cout<<q.top()<<" ";
  q.push(50);
  cout<<q.top()<<" ";
  cout<<q.size();
  return 0;
}