#include <vector>
#include <time.h>

#include "BinaryTree.h"

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
    int r = (i + 1) * rand() / RAND_MAX;
    Exch<T>(array, i, r);
  }
}

int main (int argc, char *argv[])
{
  srand(time(0));
  
  std::vector<int> inputData;
  const int N = 30;
  inputData.resize(N);

  for (int i = 0; i < N; ++i)
    inputData[i] = 30 * rand() / RAND_MAX;

  Shuffle(inputData);

  BinaryTree<int> tree(inputData);

  tree.InorderTreeWalk();

  tree.TreeSearch(5);

  std::cout << "Tree min val: " << tree.TreeMinimum() << std::endl;
  std::cout << "Tree max val: " << tree.TreeMaximum() << std::endl;

  std::cout << "Tree successor key: " << tree.TreeSuccessor(5) << std::endl;

  tree.TreeInsert(19);

  tree.InorderTreeWalk();

  tree.DeleteNode(19);

  tree.InorderTreeWalk();


  return 0;
}