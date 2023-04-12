struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	void deleteNode(ListNode* node) 
	{
		if (node == nullptr)
			return;

		ListNode* nextNode = node->next;

		if (nextNode == nullptr)
			return;

		while (true)
		{
			node->val = nextNode->val;
			if (nextNode->next == nullptr)
			{
				delete node->next;
				node->next = nullptr;
				break;
			}
			else
			{
				node = nextNode;
				nextNode = nextNode->next;
			}
		}
	}
};

int main()
{

}