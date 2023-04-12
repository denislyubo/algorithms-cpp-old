
namespace DataStructures
{
template <class T>
class Stack
{
public:
  Stack();
  ~Stack();
  void Push_back(T item);
  T Pop();

private:
  T *m_buffer;
  int m_currentSize;
  int m_currentTop;

};

template <class T>
Stack<T>::Stack()
{
  m_buffer = nullptr;
  m_currentSize = 0;
  m_currentTop = -1;
}

template <class T>
Stack<T>::~Stack()
{
  delete m_buffer;
}

template <class T>
void Stack<T>::Push_back(T item)
{
  if (m_currentSize == 0)
  {
    m_buffer = new T[2];
    m_currentSize+=2;
  }
  else if (m_currentTop == m_currentSize - 1)
  {
    m_currentSize *= 2;
    T *tempBuffer = new T[m_currentSize];
    for (int i = 0; i <= m_currentTop; ++i)
      tempBuffer[i] = m_buffer[i];
    delete[] m_buffer;
    m_buffer = tempBuffer;
    m_buffer[++m_currentTop] = item;
  }
  else
    m_buffer[++m_currentTop] = item;
}

template <class T>
T Stack<T>::Pop()
{
  if (m_currentTop >= 0)
  {
    if (m_currentTop < m_currentSize / 4)
    {
      m_currentSize /= 2;
      T *tempBuffer = new T[m_currentSize];
      for (int i = 0; i <= m_currentTop; ++i)
        tempBuffer[i] = m_buffer[i];
      delete[] m_buffer;

      m_buffer = tempBuffer;
    }
    return m_buffer[m_currentTop--];
  }
  else
    return T(0);
}


} //namespace DataStructures