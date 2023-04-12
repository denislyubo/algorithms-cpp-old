#include <vector>

using namespace std;

class Solution 
{
public:
  static bool searchMatrix(vector<vector<int>>& matrix, int target) 
  {
    int m = matrix.size();
    int n = m > 0 ? matrix[0].size() : 0;

    if (m == 0 || n == 0)
      return false;

    if (target < matrix[0][0] || target > matrix[m - 1][n - 1])
      return false;

    return SearchMatrix(matrix, 0, 0, m - 1, n - 1, target);
  }

  static bool SearchMatrix(vector<vector<int>>& matrix, int ib, int jb, int ie, int je, int target)
  {
    int split_i = 0;
    int split_j = 0;

    if ()
    
    if ((ib >= ie) && (jb != je))
    {
      split_i = ib;
      split_j = (je + jb) / 2;
    }
    else if ((ib != ie) && (jb >= je))
    {
      split_i = (ie + ib) / 2;
      split_j = jb;
    }
    else if ((ib != ie) && (jb != je))
    {
      split_i = (ie + ib) / 2;
      split_j = (je + jb) / 2;
    }
    else
      return false;

    if (target == matrix[split_i][split_j])
      return true;

    if (target < matrix[split_i][split_j])
    {
      if (SearchMatrix(matrix, ib, jb, ie, split_j - 1, target) ||
        SearchMatrix(matrix, ib, split_j, split_i - 1, je, target))
        return true;
    }
    else
    {
      if (SearchMatrix(matrix, split_i + 1, jb, ie, split_j, target) ||
        SearchMatrix(matrix, ib, split_j + 1, ie, je, target))
        return true;
    }

    return false;
  }
};

int main(int argc, char* argv[])
{
  vector<vector<int> > matrix;

  matrix.resize(5);
  for (int i = 0; i < 5; ++i)
    matrix[i].resize(5);

  matrix[0][0] = 1;  matrix[0][1] =  4; matrix[0][2] =  7; matrix[0][3] = 11; matrix[0][4] = 15;
  matrix[1][0] = 2;  matrix[1][1] =  5; matrix[1][2] =  8; matrix[1][3] = 12; matrix[1][4] = 19;
  matrix[2][0] = 3;  matrix[2][1] =  6; matrix[2][2] =  9; matrix[2][3] = 16; matrix[2][4] = 22;
  matrix[3][0] = 10; matrix[3][1] = 13; matrix[3][2] = 14; matrix[3][3] = 17; matrix[3][4] = 24;
  matrix[4][0] = 18; matrix[4][1] = 21; matrix[4][2] = 23; matrix[4][3] = 26; matrix[4][4] = 30;

  bool found = Solution::searchMatrix(matrix, 5);
  return 0;
}