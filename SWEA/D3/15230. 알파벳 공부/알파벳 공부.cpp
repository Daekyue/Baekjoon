#include <bits/stdc++.h>

using namespace std;

char alpha[26];
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (int i = 0; i < 26; i++)
	{
		alpha[i] = 'a' + i;
	}

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int count = 0;
		string str;
		cin >> str;
		
		for (int i = 0; i < str.length(); i++)
		{
			if (alpha[i] == str[i])
				count++;
            else
                break;
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}