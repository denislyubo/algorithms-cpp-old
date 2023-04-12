#include <map>
#include <vector>
#include <string>

using namespace std;

void calcWordsLengthsCount(const std::vector<string>& text, std::map<int, int> &lengthToCount) {
	for (const auto& word : text) {
		const auto curLen = word.length();
		std::map<int, int>::iterator& pos = lengthToCount.find(curLen);
		if (pos != lengthToCount.end()) {
			pos->second++;
		}
		else {
			lengthToCount[curLen] = 1;
		}
	}
}

int main() {
	std::vector<string> text = { "Apraa", "fd", "trtr", "rewq" };
	map<int, int> lengthToCount;
	calcWordsLengthsCount(text, lengthToCount);
	return 0;
}