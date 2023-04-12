#include <algorithm>
#include <stdio.h>      /* printf, scanf, puts, NULL */
#include <stdlib.h>     /* srand, rand */
#include <fstream>
#include <time.h>       /* time */
#include <iostream> 


using namespace std;
void GenerateRandomIntArray(int array[], int length)
{
  srand(time(NULL));

  for (int i = 0; i < length; ++i)
  {
    array[i] = int(10 * rand() / RAND_MAX);
  }
}

int FindDividingElement(int array[], int length)
{
  if (length <= 2)
    return -1;

  int sum1 = 0, sum2 = 0;

  sum1 = array[0];

  for (int i = 2; i < length; ++i)
    sum2 += array[i];

  for (int i = 1; i < length - 1; ++i)
  {
    if (sum1 == sum2)
      return i + 1; // number, not index!
    else
    {
      sum1 += array[i];
      sum2 -= array[i + 1];
    }
  }

  return -1;
}

int main(int argc, char *argv[])
{
  const int length = 11;
  int array[length];

  GenerateRandomIntArray(array, length);

 /* for (int i = 0; i < length; ++i)
    array[i] = 1;*/

  for (int i = 0; i < length; ++i)
    std::cout << ' ' << array[i];
  std::cout << '\n';

  std::cout << FindDividingElement(array, length) << "\n";
  
  int a;
  std::cin >> a;

  return 0;
}