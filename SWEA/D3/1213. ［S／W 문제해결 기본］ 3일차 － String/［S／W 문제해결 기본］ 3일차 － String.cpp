#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case, t;
	string fi, str;
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> t;
		cin >> fi;
		cin >> str;
		int count = 0;
		for (int i = 0; i < str.length(); i++)
		{
			if (fi[0] == str[i])
			{
				int j = 0;
				while (fi[j] == str[i + j] && i+j != str.length())
					j++;
				if (j == fi.length())
					count++;
			}
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}