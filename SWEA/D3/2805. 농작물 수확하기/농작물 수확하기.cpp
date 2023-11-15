#include <bits/stdc++.h>

using namespace std;

int num[49][49];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		memset(num, 0, sizeof(num));
		int sum = 0;
		for (int i = 0; i < N; i++)	// 행 합
		{
			string str;
			cin >> str;
			for (int j = 0; j < N; j++)
				num[i][j] = str[j] - '0';
		}
		
		for (int i = 0; i <= N / 2; i++)
		{
			int j = N / 2 - i;
			if (j == N / 2)
			{
				sum += num[i][j];
				continue;
			}
			while (j != N / 2 + i +1)
			{
				sum += num[i][j];
				j++;
			}
		}
		for (int i = 0; i < N / 2; i++)
		{
			int j = N / 2 - i;
			if (j == N / 2)
			{
				sum += num[N - i - 1][j];
				continue;
			}
			while (j != N / 2 + i +1)
			{
				sum += num[N - i - 1][j];
				j++;
			}
		}

		cout << "#" << test_case << " " << sum << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}