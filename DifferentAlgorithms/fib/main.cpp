#include <vector>
using namespace std;

void Fibonachi(int begin, int end, vector<int> result)
{
	int a = 1, b = 1;
	int c = 0;

	while (c <= end)
	{
		c = a + b;

		if (c >= begin)
		{
			result.push_back(c);
		}

		a = b;
		b = c;
	}
}


int main(int argc, char* argv[])
{

}