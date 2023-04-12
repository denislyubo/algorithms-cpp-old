#include <vector>
#include <time.h>

#define DllExport   __declspec( dllexport )

template <typename T>
class Randomizer
{
public:
  DllExport static void GenerateRandomArray(std::vector<T> &array, int N, int minVal = 0, int maxVal = 100);
  DllExport static int GenerateRandomNumber(int N);
};

template <typename T>
void Randomizer<T>::GenerateRandomArray(std::vector<T> &array, int N, int minVal = 0, int maxVal = 100)
{
  if (N > 0)
    array.resize(N);

  srand(time(NULL));

  for (int i = 0; i < N; ++i)
    array[i] = minVal + ((double)rand() / RAND_MAX) * (maxVal - minVal);
}

template <typename T>
int Randomizer<T>::GenerateRandomNumber(int N)
{
  if (N > 0)
  {
    srand(time(NULL));
    return 1 + rand() % N;
  }
  else
    return -1;
}

Randomizer < double > ;
Randomizer < float >;