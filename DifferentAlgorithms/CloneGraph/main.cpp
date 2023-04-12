#include <vector>
#include <queue>
#include <map>

using namespace std;

 //Definition for undirected graph.
struct UndirectedGraphNode 
{
    int label;
    vector<UndirectedGraphNode *> neighbors;
    UndirectedGraphNode(int x) : label(x) {};
};

class Solution 
{
public:
    static UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) 
    {
      if (!node)
        return NULL;

      UndirectedGraphNode *resultNode = new UndirectedGraphNode(node->label);

      queue<UndirectedGraphNode *> q;
      map<UndirectedGraphNode *, bool> used;
      queue<UndirectedGraphNode *> qRes;

      map<UndirectedGraphNode *, UndirectedGraphNode *> mapOrigToCopy;
      mapOrigToCopy[node] = resultNode;

      q.push(node);
      used[node] = true;

      qRes.push(resultNode);

      UndirectedGraphNode *currentNode, *currentResultNode;
      while (!q.empty())
      {
        currentNode = q.front();
        q.pop();

        currentResultNode = qRes.front();
        qRes.pop();

        vector<UndirectedGraphNode *> &neighbors = currentNode->neighbors;
        for (int i = 0, len = neighbors.size(); i < len; ++i)
        {
          if (used.find(neighbors[i]) == used.end())
          {
            used[neighbors[i]] = true;
            q.push(neighbors[i]);

            currentResultNode->neighbors.push_back(new UndirectedGraphNode(neighbors[i]->label));
            qRes.push(currentResultNode->neighbors[i]);
            mapOrigToCopy[neighbors[i]] = currentResultNode->neighbors[i];
          }
          else
          {
            map<UndirectedGraphNode *, UndirectedGraphNode *>::iterator it = mapOrigToCopy.find(neighbors[i]);
            UndirectedGraphNode *copy = it->second;
            currentResultNode->neighbors.push_back(copy);
          }
        }

      }

      return resultNode;
    }
};

int main (int argc, char *argv[])
{
  //UndirectedGraphNode *node = new UndirectedGraphNode(5);
  //node->neighbors.push_back(new UndirectedGraphNode(7));
  //node->neighbors.push_back(new UndirectedGraphNode(8));
  //node->neighbors[1]->neighbors.push_back(node->neighbors[1]);

  UndirectedGraphNode *node = new UndirectedGraphNode(0);
  node->neighbors.push_back(new UndirectedGraphNode(0));
  node->neighbors[0]->neighbors.push_back(new UndirectedGraphNode(0));

  UndirectedGraphNode *res = Solution::cloneGraph(node);

  return 0;
}