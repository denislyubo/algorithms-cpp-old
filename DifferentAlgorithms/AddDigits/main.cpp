#include <vector>

using namespace std;

class Solution {
public:
	int addDigits(int num) {

	}

	vector<short int> FindDigits(int num)
	{
		int power = 1;
		int tenPower = 10;

		while (true)
		{
			if (num % tenPower < num)
			{
				tenPower /= 10;
				power--;
				break;
			}
			tenPower *= 10;
			power++;
		}

		for (int i = power; i > 0; --i)
		{

		}
	}


};

int main()
{

}