#include <set>
#include <algorithm>

#include "PriorityQueue.h"

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
  const int SIZE = 10;

  std::vector<TYPE> array(SIZE);
  std::generate(array.begin(), array.end(), URandGen(SIZE));

  PriorityQueue<TYPE> queue;
  queue.BuildMaxHeap(array);

  TYPE val = queue.HeapMaximum();

  queue.MaxHeapInsert(7);
  return 0;
}