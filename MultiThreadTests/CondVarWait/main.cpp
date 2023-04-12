#include <iostream>
#include <queue>
#include <thread>
#include <mutex>

using namespace std;

mutex mut;
condition_variable data_cond;
queue<char> data_queue;

void PrepareData()
{
	char a = '0';
	lock_guard<mutex> lk(mut);
	data_queue.push(a);

}

void ProcessData()
{
	unique_lock<mutex> lk(mut);
	data_cond.wait(lk, [] {return !data_queue.empty(); });
	char a = data_queue.front();
	data_queue.pop();
	lk.unlock();
	cout << "Result processed: " << a << endl;
}

int main() {
	thread t1(PrepareData);
	thread t2(ProcessData);


	t1.detach();
	t2.detach();

	char b{};
	cin >> b;

	return 0;
}