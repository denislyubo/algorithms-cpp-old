#include <stack>

class Queue {
public:
  // Push element x to the back of queue.
  void push(int x) 
  {
    while (stack1.size() != 0)
    {
      stack2.push(stack1.top());
      stack1.pop();
    }

    stack1.push(x);

    while (stack2.size() != 0)
    {
      stack1.push(stack2.top());
      stack2.pop();
    }
  }

  // Removes the element from in front of queue.
  void pop(void) 
  {
    stack1.pop();
  }

  // Get the front element.
  int peek(void) 
  {
    return stack1.top();
  }

  // Return whether the queue is empty.
  bool empty(void) 
  {
    return stack1.empty();
  }

private:
  std::stack<int> stack1;
  std::stack<int> stack2;
};

int main(int argc, char *argv[])
{
  
  return 0;
}