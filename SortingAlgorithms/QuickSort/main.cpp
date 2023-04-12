#include <Randomizer/Randomizer.h>

template <typename T>
bool Less(const T &a, const T &b)
{
  if (a < b)
    return true;
  else
    return false;
}

template <typename T>
void Exch(std::vector<T> &array, int i, int j)
{
  if (i == j)
    return;

  T temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

template <typename T>
void Shuffle(std::vector<T> &array)
{
  int N = array.size();

  for (int i = 0; i < N; ++i)
  {
    int r = Randomizer<T>::GenerateRandomNumber(i + 1);
    Exch<T>(array, i, r);
  }
}

template <typename T>
int Partition(std::vector<T> &array, int lo, int hi)
{
  int i = lo, j = hi + 1;
  while (true)
  {
    while (array[++i] < array[lo])
      if (i == hi)
        break;

    while (array[lo] <= array[--j])
      if (j == lo)
        break;

    if (i >= j)
      break;
    
    Exch<T>(array, i, j);
  }

  Exch<T>(array, lo, j);
  return j;
}

template <typename T>
void Sort(std::vector<T> &array, int lo, int hi)
{
  if (hi <= lo)
    return;

  int j = Partition<T>(array, lo, hi);

  Sort<T>(array, lo, j - 1);
  Sort<T>(array, j + 1, hi);
}

template <typename T>
void QuickSort(std::vector<T> &array)
{
  Shuffle<T>(array);
  Sort<T>(array, 0, array.size() - 1);
}

int main(int argc, char *argv[])
{
  std::vector<double> array;
  Randomizer<double>::GenerateRandomArray(array, 10);

  QuickSort<double>(array);

  return 0;
}