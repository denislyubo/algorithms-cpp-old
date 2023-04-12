#include <stdlib.h> 
#include <vector>
#include <time.h>  

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
void SelectionSort(std::vector<T> &array)
{
  int len = array.size();

  for (int i = 0; i < len; ++i)
  {
    int min = i;

    for (int j = i + 1; j < len; ++j)
      if (Less<T>(array[j], array[min]))
        min = j;

    Exch<T>(array, i, min);
  }
}

int main(int argc, char *argv[])
{
  std::vector<double> array;

  Randomizer<double>::GenerateRandomArray(array, 100);

  SelectionSort<double>(array);


  return 0;
}