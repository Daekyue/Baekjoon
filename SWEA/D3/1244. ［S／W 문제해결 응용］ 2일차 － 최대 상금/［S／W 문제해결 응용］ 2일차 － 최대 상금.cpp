#include <bits/stdc++.h>

using namespace std;

string s;
int n, answer;

void func(int k)
{
	if (k == n)
	{
		answer = max(answer, stoi(s));
		return;
	}
	for (int i = 0; i < s.size(); i++)
	{
		for (int j = i+1; j < s.size(); j++)
		{
			if (i != j)
			{
				swap(s[i], s[j]);
				func(k + 1);
				swap(s[j], s[i]);
			}
		}
	}
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> s >> n;
		answer = 0;
		if (n > s.size())
			n = s.size();
		func(0);
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}