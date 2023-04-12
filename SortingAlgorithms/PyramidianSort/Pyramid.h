#include <iterator>
#include <vector>

template <typename U, class T = std::vector<U> >
class Pyramid
{
public:
  Pyramid();
  ~Pyramid();

  void BuildMaxHeap(T &array);
  void PyrSort(T &array);

private:
  void MaxHeapify(int i);

  int Left(int i)
  {
    return i << 1;
  }

  int Right(int i)
  {
    return (i << 1) | 1;
  }

  int Parent(int i)
  {
    return i >> 1;
  }

private:
  T m_array;
  unsigned int m_pyrSize;
};

template <typename U, class T>
Pyramid<U, T>::Pyramid()
{
}

template <typename U, class T>
Pyramid<U, T>::~Pyramid()
{
}

template <typename U, class T>
void Pyramid<U, T>::BuildMaxHeap(T &array)
{
  int len = array.size();
  if (len < 3)
    return;
  m_array.resize(len);
  std::copy(array.begin(), array.end(), m_array.begin());

  m_pyrSize = m_array.size();

  for (int i = m_pyrSize / 2 - 1; i >= 0; --i)
    MaxHeapify(i);
}

template <typename U, class T>
void Pyramid<U, T>::MaxHeapify(int i)
{
  int l = Left(i + 1) - 1;
  int r = Right(i + 1) - 1;
  int largest;
  if (l < m_pyrSize && m_array[l] > m_array[i])
    largest = l;
  else
    largest = i;

  if (r < m_pyrSize && m_array[r] > m_array[largest])
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
void Pyramid<U, T>::PyrSort(T &array)
{
  BuildMaxHeap(array);

  for (int i = m_array.size() - 1; i > 0; --i)
  {
    U temp = m_array[0];
    m_array[0] = m_array[i];
    m_array[i] = temp;

    m_pyrSize--;

    MaxHeapify(0);
  }
}