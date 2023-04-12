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
void ShellSort(std::vector<T> &array)
{
  int N = array.size();
  int h = 1;
  while (h < N / 3)
    h = 3 * h + 1;

  while (h >= 1)
  { 
    for (int i = h; i < N; ++i)
      for (int j = i; j >= h && Less<T>(array[j], array[j - h]); j -= h)
        Exch<T>(array, j, j - h);
    h /= 3;
  }
}

int main(int argc, char *argv[])
{
  std::vector<double> array;
  Randomizer<double>::GenerateRandomArray(array, 100);

  ShellSort<double>(array);

  return 0;
}