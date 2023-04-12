#include "Randomizer.h"

int main(int argc, char* argv[])
{
  std::vector<double> array;
  int N = 100;
  Randomizer<double>::GenerateRandomArray(array, N);
}