#include <future>
#include <thread>
#include <chrono>
#include <random>
#include <iostream>
#include <exception>

using namespace std;

int DoSomething(char c)
{
	std::default_random_engine dre(c);
	std::uniform_int_distribution<int> id(10, 1000);

	for (int i = 0; i < 10; ++i)
	{
		this_thread::sleep_for(chrono::milliseconds(id(dre)));
		cout.put(c).flush();
	}

	return c;
}

int func1()
{
	return DoSomething('.');
}

int func2()
{
	return DoSomething('+');
}

int main()
{
	std::cout << "starting func1() in background"
		<< " and func2() in foreground:" << endl;

	future<int> result1(std::async(func1));
	int result2 = func2();

	int result = result1.get() + result2;

	cout << "\nresult of func1() + func2(): " << result << endl;

	int a;
	cin >> a;
}