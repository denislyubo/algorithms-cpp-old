#include <string>
#include <set>

#include <iostream>

using namespace std;

class Solution {
public:
	static bool isAnagram(string s, string t) {
		multiset<char> sMultiSet(s.cbegin(), s.cend());

		for (int i = 0, size = t.size(); i < size; ++i)
		{
			auto it = sMultiSet.find(t[i]);

			if (it == sMultiSet.end())
				return false;
			else
				sMultiSet.erase(it);
		}

		if (sMultiSet.empty())
			return true;
		else
			return false;
	}
};

int main()
{
	string a("ab");
	string b("a");

	cout << Solution::isAnagram(a, b);

	int a1;
	cin >> a1;

}