 struct List_t {
	List_t(int val) :payload(val) {}
	struct List_t * next = nullptr;
	int payload;
};
void delEachFith(List_t* head) {
	List_t* curEl = head, *prevEl = head;
	int counter = 0;

	while (curEl != nullptr) {
		counter++;

		if (counter == 5) {
			List_t* next = curEl->next;
			prevEl->next = next;
			delete curEl;
			counter = 0;
			curEl = next;
			continue;
		}

		prevEl = curEl;
		curEl = curEl->next;
	}
}

List_t* makeListWithLength(int N) {
	
	if (N <= 0)return nullptr;

	List_t* head = new List_t(0);
	List_t* curEl = head, *next = nullptr;

	for (int i = 1; i < N; i++)
	{
		next = new List_t(i);
		curEl->next = next;
		curEl = next;
	}

	curEl->next = nullptr;

	return head;
}

void purgeList(List_t* head) {
	List_t* curEl = head, *next = nullptr;
	
	while (curEl != nullptr){
		next = curEl->next;
		delete curEl;
		curEl = next;
	}
}


int main() {
	List_t* head = makeListWithLength(1);

	delEachFith(head);

	purgeList(head);

	return 0;
}