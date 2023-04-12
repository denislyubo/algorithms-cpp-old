#include <vector>
#include <iostream>
#include <gtest/gtest.h>

using namespace std;


/**
* Definition for singly-linked list.*/


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
	static ListNode* deleteDuplicates(ListNode* head) {
		
		ListNode *currentNode = head, *prevNode = head;
		while (currentNode != nullptr) {
			if (currentNode->next == nullptr)
				return head;
			currentNode = currentNode->next;
			if (currentNode->val == prevNode->val) {
				prevNode->next = currentNode->next;
			}
			else {
				prevNode = currentNode;
			}
		}
		return head;
	}
};



TEST(LinkedListTest, ListEmpty) {
	ListNode *head = nullptr;

	Solution::deleteDuplicates(head);
	EXPECT_EQ(nullptr, head);
}

TEST(LinkedListTest, ListOneEl) {
	ListNode *head = new ListNode(1);

	Solution::deleteDuplicates(head);
	EXPECT_NE(nullptr, head);
	EXPECT_EQ(nullptr, head->next);
}

int main(int argc, char* argv[]) {
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();

	
	Solution::deleteDuplicates(nullptr);

	int a;
	cin >> a;

	return 0;
}