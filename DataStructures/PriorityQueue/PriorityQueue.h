#include <iterator>
#include <vector>

#pragma once

#define MIN -1e200;

template <typename U, class T = std::vector<U> >
class PriorityQueue
{
public:
  PriorityQueue();
  ~PriorityQueue();

  void BuildMaxHeap(T &array);
  U HeapMaximum() const
  {
    return m_array[0];
  }

  U HeapExtractMax();
  void HeapInkreaseKey(int i, U value);
  void MaxHeapInsert(U value);

private:
  void MaxHeapify(int i);

  int Left(int i) const
  {
    return i << 1;
  }

  int Right(int i) const
  {
    return (i << 1) | 1;
  }

  int Parent(int i) const
  {
    return i >> 1;
  }

private:
  T m_array;
  unsigned int m_heapSize;
};

template <typename U, class T>
PriorityQueue<U, T>::PriorityQueue()
{
}

template <typename U, class T>
PriorityQueue<U, T>::~PriorityQueue()
{
}

template <typename U, class T>
void PriorityQueue<U, T>::BuildMaxHeap(T &array)
{
  int len = array.size();
  if (len < 3)
    return;
  m_array.resize(len);
  std::copy(array.begin(), array.end(), m_array.begin());

  m_heapSize = m_array.size();

  for (int i = m_heapSize / 2 - 1; i >= 0; --i)
    MaxHeapify(i);
}

template <typename U, class T>
void PriorityQueue<U, T>::MaxHeapify(int i)
{
  int l = Left(i + 1) - 1;
  int r = Right(i + 1) - 1;
  int largest;
  if (l < m_heapSize && m_array[l] > m_array[i])
    largest = l;
  else
    largest = i;

  if (r < m_heapSize && m_array[r] > m_array[largest])
    largest = r;


  if (largest != i)
  {
    U temp = m_array[i];
    m_array[i] = m_array[largest];
    m_array[largest] = temp;

    MaxHeapify(largest);
  }
}
template <typename U, class T>
U PriorityQueue<U, T>::HeapExtractMax()
{
  if (!m_heapSize)
    return -1;

  U max = m_array[0];

  m_array[0] = m_array[m_heapSize - 1];
  m_heapSize--;
  MaxHeapify(0);

  return max;
}

template <typename U, class T>
void PriorityQueue<U, T>::HeapInkreaseKey(int i, U value)
{
  if (value < m_array[i])
    return;

  m_array[i] = value;

  while (i > 0 && m_array[Parent(i)] < m_array[i])
  {
    U temp = m_array[i];
    m_array[i] = m_array[Parent(i)];
    m_array[Parent(i)] = temp;

    i = Parent(i);
  }
}

template <typename U, class T>
void PriorityQueue<U, T>::MaxHeapInsert(U value)
{
  m_heapSize++;
  m_array.resize(m_heapSize);
  m_array[m_heapSize - 1] = MIN;

  HeapInkreaseKey(m_heapSize - 1, value);
}