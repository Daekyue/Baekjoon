#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		string str;
		cin >> str;
		int count = 0;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (str[i] == '(')
			{
				if (str[i + 1] == ')')
					i++;
				count++;
			}
			else if (str[i] == ')')
			{
				count++;
			}
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}