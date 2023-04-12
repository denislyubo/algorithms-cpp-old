#include <vector>

#pragma once

//Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution 
{
public:
    static ListNode *FindMinListNode(std::vector<ListNode*> &curNodes)
    {
     
      int len = curNodes.size();
      if (len)
      {
         ListNode *minNode = NULL;
         int minIndx = -1;
         for (int i = 0; i < len; ++i)
           if (curNodes[i] != NULL)
           {
             minNode = curNodes[i];
             minIndx = i;
             break;
           }

           if (!minNode)
             return NULL;
         
         for (int i = 0; i < len; ++i)
         {
           if (curNodes[i] != NULL)
             if (curNodes[i]->val < minNode->val)
             {
               minNode = curNodes[i];
               minIndx = i;
             }
         }
         
         if (minNode)
         {
           curNodes[minIndx] = curNodes[minIndx]->next;
           return minNode;
         }
      }

      return NULL;
    }

    static ListNode* mergeKLists(std::vector<ListNode*>& lists) 
    {
      ListNode *head = FindMinListNode(lists);
      if (!head)
        return NULL;

      ListNode *node = FindMinListNode(lists);
      head->next = node;
      if (!node)
        return head;

      ListNode *newNode = NULL;
      while(node)
      {
        newNode = FindMinListNode(lists);

        if (newNode)
        {
          node->next = newNode;
          node = newNode;
        }
        else
          {
            node->next = NULL;
            return head;
          }
      }
    }
};


int main (int argc, char *argv[])
{
  ListNode *head1 = NULL;/*new ListNode(5);*/
  //head1->next = NULL;
  /*ListNode *head1Next = new ListNode(6);
  head1->next = head1Next;
  head1Next->next = NULL;*/

  ListNode *head2 = NULL;/*new ListNode(3);
  ListNode *head2Next = new ListNode(7);
  head2->next = head2Next;
  head2Next->next = NULL;*/

  std::vector<ListNode *> lists;
  lists.push_back(head1);
  lists.push_back(head2);

  ListNode * res = Solution::mergeKLists(lists);

  return 0;
}