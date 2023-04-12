#include <iostream>

using namespace std;

class Solution 
{
public:
	static bool canWinNim(int n) 
	{
		if (n > 4)
		{
			if (n % 4 == 0)
				return 0;
			else
				return 1;
		}

		if (n == 4)
			return 0;

		if (n < 4)
			return 1;

	}
};

int main()
{
	const int n = 5;

	Solution::canWinNim(n);

	int a;
	cin >> a;
}