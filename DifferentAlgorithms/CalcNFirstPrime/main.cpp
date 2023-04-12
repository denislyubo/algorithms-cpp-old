#include <array>

static const int N = 25;

constexpr int numOfEl()
{
	return N;
}


void calcNFirstPrimes(int N, std::array<int, numOfEl()>& arr) {
	if (N < 1) return;
	if (N == 1) { arr[0] = 2; return; }

	int foundPrimes = 1;
	int onPrimeCandidate = 3;
	arr[0] = 2;
	bool breakFlag = false;

	while (foundPrimes < N) {
		for (int i = 2; i <= onPrimeCandidate / 2; ++i) {
			if (onPrimeCandidate%i == 0) {
				onPrimeCandidate++;
				breakFlag = true;
				break;
			}
		}
		if (breakFlag) { breakFlag = false;  continue;  }

		arr[foundPrimes] = onPrimeCandidate;
		foundPrimes++;
		onPrimeCandidate += 2;
	}
}

int main() {
	std::array<int, numOfEl()> arr;
	calcNFirstPrimes(numOfEl(), arr);
	return 0;
}