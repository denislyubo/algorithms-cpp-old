#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

const int N = 10;

class Solution 
{
public:
  static vector<string> findRepeatedDnaSequences(string s)
  {
    int begInd = 0;
    unordered_map<int, int> map;
    vector<string> ans;

    if (s.size() < 11)
      return ans;

    string tempStr;
    while (true)
    {
      tempStr = s.substr(begInd, N);
      int tempStrHash = 0;
      for (int j = 0; j < N; ++j)
        tempStrHash = tempStrHash << 2 | (tempStr[j] - 'A' + 1) % 5;

      if (map[tempStrHash]++ == 1)
        ans.push_back(tempStr);

      if (begInd < s.size() - N)
        begInd++;
      else
        break;
    }

    return ans;
  }


  template <class Key>
  struct KeyHasher
  {
    int operator()(const Key& k) const
    {
      int tempStrHash = 0;
      for (int j = 0; j < N; ++j)
        tempStrHash = tempStrHash << 2 | (k[j] - 'A' + 1) % 5;

      return tempStrHash;
    }
  };





  static vector<string> findRepeatedDnaSequences1(string s)
  {
    int begInd = 0;
    unordered_map<string, int, KeyHasher<string> > map;
    vector<string> ans;

    if (s.size() < 11)
      return ans;

    string tempStr;
    while (true)
    {
      tempStr = s.substr(begInd, N);

      if (map[tempStr]++ == 1)
        ans.push_back(tempStr);

      if (begInd < s.size() - N)
        begInd++;
      else
        break;
    }

    return ans;
  }
};


int main(int argc, char *argv[])
{
  vector<string> res = Solution::findRepeatedDnaSequences("CAAAAAAAAAC");

  vector<string> res1 = Solution::findRepeatedDnaSequences1("CAAAAAAAAAC");
  return 0;
}