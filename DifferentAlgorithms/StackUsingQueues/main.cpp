#include <queue>

class Stack {
public:
  // Push element x onto stack.
  void push(int x) 
  {
    if (m_queue1.size() == 0)
      m_queue1.push(x);
    else
    {
      while (m_queue1.size() != 0)
      {
        m_queue2.push(m_queue1.front());
        m_queue1.pop();
      }
      
      m_queue1.push(x);

      while (m_queue2.size() != 0)
      {
        m_queue1.push(m_queue2.front());
        m_queue2.pop();
      }
    }
  }

  // Removes the element on top of the stack.
  void pop() 
  {
    m_queue1.pop();
  }

  // Get the top element.
  int top() 
  {
    return m_queue1.front();
  }

  // Return whether the stack is empty.
  bool empty() 
  {
    return m_queue1.empty();
  }
private:
  std::queue<int> m_queue1;
  std::queue<int> m_queue2;
};

int main (int argc, char *argv[])
{

  return 0;
}