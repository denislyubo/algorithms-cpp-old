#include <set>
#include <algorithm>

#include "Pyramid.h"

class URandGen
{
  std::set<int> used;
  int limit;
public:
  URandGen(int lim):
    limit(lim)
  {}

  int operator()()
  {
    while (true)
    {
      int i = int(std::rand()) % limit;

      if (used.find(i) == used.end())
      {
        used.insert(i);
        return i;
      }
    }
  }
};

int main(int argc, char *argv[])
{
  typedef int TYPE;
  const int SIZE = 1000;
  
  //std::vector<TYPE> array = {1, 5, 3, 7, 8, 2, 9, 4, 2, 11, 6, 12};

  std::vector<TYPE> array(SIZE);
  std::generate(array.begin(), array.end(), URandGen(SIZE));

  Pyramid<TYPE> pyramid;
  pyramid.BuildMaxHeap(array);

  pyramid.PyrSort(array);
  return 0;
}