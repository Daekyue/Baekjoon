#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string s;
		cin >> s;

		int count = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] != s[i + 1])
				count++;
		}
		if (s[0] == '1')
			count++;

		cout << "#" << test_case << " " << count-1 << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}