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
bool IsSorted(std::vector<T> &array, int lo, int hi)
{
  for (int i = lo; i < hi; ++i)
    if (!Less<T>(array[i], array[i + 1]))
      return false;

  return true;
}

template <typename T>
void Merge(std::vector<T> &array, std::vector<T> &aux, int lo, int mid, int hi)
{
  _ASSERT(IsSorted<T>(array, lo, mid));
  _ASSERT(IsSorted<T>(array, mid + 1, hi));

  for (int k = lo; k <= hi; ++k)
    aux[k] = array[k];

  int i = lo, j = mid + 1;

  for (int k = lo; k <= hi; ++k)
  {
    if (i > mid)
      array[k] = aux[j++];
    else if (j > hi)
      array[k] = aux[i++];
    else if (Less<T>(aux[j], aux[i]))
      array[k] = aux[j++];
    else
      array[k] = aux[i++];
  }

  _ASSERT(IsSorted<T>(array, lo, hi));
}

template <typename T>
void Sort(std::vector<T> &array, std::vector<T> &aux, int lo, int hi)
{
  if (hi <= lo)
    return;

  int mid = lo + (hi - lo) / 2.;

  Sort<T>(array, aux, lo, mid);
  Sort<T>(array, aux, mid + 1, hi);

  Merge<T>(array, aux, lo, mid, hi);
}

template <typename T>
void MergeSort(std::vector<T> &array)
{
  std::vector<T> aux(array.size());

  Sort<T>(array, aux, 0, aux.size() - 1);
}

int main(int argc, char *argv[])
{
  std::vector<double> array;
  Randomizer<double>::GenerateRandomArray(array, 100);

  MergeSort<double>(array);

  return 0;
}