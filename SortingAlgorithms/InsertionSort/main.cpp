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
  T temp = array[i];
  array[i] = array[j];
  array[j] = temp;
}

template <typename T>
void InsertionSort(std::vector<T> &array)
{
  int len = array.size();

  for (int i = 0; i < len; ++i)
    for (int j = i; j > 0; --j)
      if (Less<T>(array[j], array[j - 1]))
        Exch<T>(array, j, j - 1);
      else
        break;
}

int main(int argc, char *argv[])
{
  std::vector<double> array;
  Randomizer<double>::GenerateRandomArray(array, 100);

  InsertionSort<double>(array);

  return 0;
}