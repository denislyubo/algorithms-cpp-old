#pragma once
namespace DataStructures
{
template<class T>
class SingleLinkedList
{
public:
  SingleLinkedList();
  ~SingleLinkedList();

  SingleLinkedList(int len, T val);

  SingleLinkedList(const SingleLinkedList<T> &src);

  void push_back(T item);
  T &pop();
  int Length() const;
  void assign(int len, T val);
  void clear();
  
  class iterator;

  iterator Find
  (
  iterator &beginIt,
  iterator &endIt,
  T &item
  ) const;
  
  iterator Insert(iterator &it, T item);
  void Invert();

  template <class U>
  class Node
  {
  public:
    Node();
    ~Node();

    void SetData(U &data);
    inline Node *GetNextNode();
    void SetNextNode(Node *pNode);
    U &GetData();

  private:
    U m_data;
    Node *m_pNextNode;
  };

  class iterator;
  friend class iterator;

  class iterator
  {
  public:
    iterator(const SingleLinkedList<T> &list):
      p(list.m_pHead)
    {}
    
    iterator(const iterator &iter) :
      p(iter.p)
    {}

    iterator() :
      p(nullptr)
    {}

    bool operator++()
    {
      if (p->GetNextNode())
        p = p->GetNextNode();
      else
        p = nullptr;

      return bool(p);
    }

    bool operator++(int)
    {
      return operator++();
    }

    T current()
    {
      if (!p)
        return 0.;

      return p->GetData();
    }

    T operator->()
    {
      return current();
    }

    T operator*()
    {
      return current();
    }

    operator bool() const
    {
      return bool(p);
    }

    bool operator==(const iterator &) const
    {
      return p == 0;
    }

    bool operator!=(const iterator &) const
    {
      return p != 0;
    }

    friend class SingleLinkedList<T>;

  private:
    typename SingleLinkedList<T>::Node<T> *p;
  };

  iterator begin() const
  {
    return iterator(*this);
  }

  iterator end() const
  {
    return iterator();
  }

private:
  Node<T> *m_pHead;
  Node<T> *m_pTail;
  int length;
};

template<class T>
SingleLinkedList<T>::SingleLinkedList()
{
  m_pHead = nullptr;
  m_pTail = nullptr;
  length = 0;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(int len, T val)
{
  assign(len, val);
}

template<class T>
void SingleLinkedList<T>::assign(int len, T val)
{
  m_pHead = new Node<T>();
  Node<T> *prevNode = m_pHead;

  for (int i = 1; i < len; ++i)
  {
    Node<T> *curNode = new Node<T>();
    curNode->SetData(val);
    prevNode->SetNextNode(curNode);
    prevNode = curNode;
  }

  m_pTail = prevNode;

  length = len;
}

template<class T>
SingleLinkedList<T>::~SingleLinkedList()
{
  clear();
}

template<class T>
void SingleLinkedList<T>::clear()
{
  Node<T> *curNode = m_pHead;

  while (curNode != nullptr)
  {
    Node<T> *nextNode = curNode->GetNextNode();
    delete curNode;
    curNode = nextNode;
  }

  length = 0;

  m_pHead = nullptr;
  m_pTail = nullptr;
}

template<class T>
SingleLinkedList<T>::SingleLinkedList(const SingleLinkedList<T> &src)
{
  this->clear();
  this->assign(src.length, 0);

  Node<T> *thisCur = m_pHead, *srcCur = src.m_pHead;
  
  while (thisCur != nullptr && srcCur != nullptr)
  {
    thisCur->SetData(srcCur->GetData());
    thisCur = thisCur->GetNextNode();
    srcCur = srcCur->GetNextNode();
  }
}

template<class T>
void SingleLinkedList<T>::push_back(T item)
{
  Node<T> *node = new Node<T>();
  node->SetData(item);

  length++;

  if (m_pHead == nullptr)
  {
    m_pHead = node;
    m_pTail = m_pHead;
  }
  else if (m_pTail != nullptr)
  {
    m_pTail->SetNextNode(node);
    m_pTail = node;
  }
}

template<class T>
T &SingleLinkedList<T>::pop()
{
  if (m_pHead == m_pTail)
  {
    T data = m_pHead->GetData();
    delete m_pHead;
    m_pHead = nullptr;
    m_pTail = nullptr;
    return data;
  }

  Node<T> *curNode = m_pHead;

  do
  {
    if (curNode->GetNextNode() == m_pTail)
    {
      length--;
      break;
    }
    curNode = curNode->GetNextNode();
  } while (true);

  T data = m_pTail->GetData();
  curNode->SetNextNode(nullptr);
  delete m_pTail;
  m_pTail = curNode;
  return data;
}

template<class T>
int SingleLinkedList<T>::Length() const
{
  return length;
}

////////////////////////////////////////////////////////////////////////////////
template<class T>
typename SingleLinkedList<T>::iterator SingleLinkedList<T>::Find
(
typename SingleLinkedList<T>::iterator &beginIt,
typename SingleLinkedList<T>::iterator &endIt,
T &item
) const
{
  SingleLinkedList<T>::Node<T> *node = beginIt.p;

  while (node != nullptr && node != endIt.p)
  {
    if (node->GetData() == item)
    {
      iterator iter;
      iter.p = node;

      return iter;
    }

    node = node->GetNextNode();
  }
  
  return iterator();
}

////////////////////////////////////////////////////////////////////////////////
template<class T>
typename SingleLinkedList<T>::iterator SingleLinkedList<T>::Insert(typename SingleLinkedList<T>::iterator &it, T item)
{
  if (it.p != nullptr)
  {
    Node<T> *node = new Node<T>();
    node->SetData(item);
    node->SetNextNode(it.p.GetNextNode());
    it.p.SetNextNode(node);

    return iterator(node);
  }
  
  return iterator();
}

template<class T>
void SingleLinkedList<T>::Invert()
{
  Node<T> *curNode = m_pHead;
  Node<T> *nextNode = curNode->GetNextNode();
  Node<T> *next1Node = nullptr;
  Node<T> *nextNextNode = nextNode->GetNextNode();

  if (nextNode == nullptr)
    return;

  if (nextNextNode == nullptr)
  {
    curNode->SetNextNode(nullptr);
    nextNode->SetNextNode(curNode);
    m_pHead = nextNode;
    m_pTail = curNode;
    return;
  }
  else
  {
    curNode->SetNextNode(nullptr);
    nextNode->SetNextNode(curNode);
    m_pTail = curNode;
  }

  while (true)
  {
    
    curNode = nextNextNode;
    
    if (!next1Node)
    {
      next1Node = curNode->GetNextNode();
      nextNextNode->SetNextNode(nextNode);
      nextNode = nullptr;
    }
    else
    {
      nextNode = curNode->GetNextNode();
      nextNextNode->SetNextNode(next1Node);
      next1Node = nullptr;
    }

    if (!next1Node && !nextNode)
      return;
    
    if(next1Node)
      nextNextNode = next1Node->GetNextNode();
    else
      nextNextNode = nextNode->GetNextNode();

    if (!nextNextNode)
    {
      if (next1Node)
      {
        next1Node->SetNextNode(curNode);
        m_pHead = next1Node;
      }
      else
      {
        nextNode->SetNextNode(curNode);
        m_pHead = nextNode;
      }
      
      return;
    }
    else
    {
      if (next1Node)
        next1Node->SetNextNode(curNode);
      else
        nextNode->SetNextNode(curNode);
    }
  }
}

template <class T>
template <class U>
SingleLinkedList<T>::Node<U>::Node()
{
  m_pNextNode = nullptr;
}

template <class T>
template <class U>
SingleLinkedList<T>::Node<U>::~Node()
{
}

template <class T>
template <class U>
void SingleLinkedList<T>::Node<U>::SetData(U &data)
{
  m_data = data;
}

template <class T>
template <class U>
typename SingleLinkedList<T>::Node<U> *SingleLinkedList<T>::Node<U>::GetNextNode()
{
  return m_pNextNode;
}

template <class T>
template <class U>
void SingleLinkedList<T>::Node<U>::SetNextNode(Node *pNode)
{
  m_pNextNode = pNode;
}

template <class T>
template <class U>
U &SingleLinkedList<T>::Node<U>::GetData()
{
  return m_data;
}

} //  namespace DataStructures
