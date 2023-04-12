#include <vector>
#include <numeric>
#include <iostream>

using namespace std;

class Solution 
{
public:
	static int bulbSwitch(int n)
	{
		int numOfBulbsOn = 0;
		vector<char> bulbsState(n, true);
		std::vector<char> prime(n, true);
		prime[0] = prime[1] = false;
		int k = 0;

		if (n == 0)
			return 0;
		if (n == 1)
			return 1;

		for (int d = 2; d <= n; ++d)
		{
			if (prime[d])
				if (d * d < n)
					for (unsigned long int j = d * d; j < n; j += d)
					{
						prime[j] = false;
						bulbsState[j] = false;
					}
			
			k = d;

			if (k > n)
				break;

			do
			{
				bulbsState[k-1] = !bulbsState[k-1];
				k += d;
			}
			while (k <= n);
		}

		accumulate(bulbsState.begin(), bulbsState.end(), numOfBulbsOn);

		return numOfBulbsOn;
	}
};

int main(int argc, char* argv[])
{
	const int n = 5;
	
	int res = Solution::bulbSwitch(n);

	cout << "Num of switched on: " << res;



	return 0;
}