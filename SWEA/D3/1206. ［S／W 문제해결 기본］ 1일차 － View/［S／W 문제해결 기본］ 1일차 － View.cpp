#include <bits/stdc++.h>

using namespace std;

int row[1005];
int dx[4] = { -2, -1, 1, 2 };

int main(int argc, char** argv)
{
	
	for (int test_case = 1; test_case <= 10; ++test_case)
	{
		int N;
		cin >> N;

		for (int i = 0; i < N; i++)
			cin >> row[i];

		int ans = 0;
		for (int i = 2; i < N - 2; i++)
		{
			int see = row[i];
			for (int j = 0; j < 4; j++)
			{
				if (row[i] - row[i + dx[j]] <= 0)
				{
					see = 0;
					break;
				}
				else if (row[i] - row[i + dx[j]] < see)
					see = row[i] - row[i + dx[j]];
			}
			ans += see;
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}