#include <bits/stdc++.h>

using namespace std;
#define num 100
int board[num + 2][num + 2];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n;
		cin >> n;
		int count = 0;
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
				cin >> board[i][j];
		}

		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (board[i][j] == 1)
				{
					int cur = i;
					while (board[cur + 1][j] != 2)
					{
						board[cur][j] = 0;
						cur++;
						if (cur >= num)
							break;
						else
							board[cur][j] = 1;
					}
				}
				else if (board[i][j] == 2)
				{
					int cur = i;
					while (board[cur - 1][j] != 1)
					{
						board[cur][j] = 0;
						cur--;
						if (cur <= 0)
							break;
						else
							board[cur][j] = 2;
					}
				}
			}
		}
		for (int i = 1; i <= num; i++)
		{
			for (int j = 1; j <= num; j++)
			{
				if (board[i][j] == 1)
					if (board[i + 1][j] == 2)
						count++;
			}
		}
		cout << "#" << test_case << " " << count << "\n";
	}
	// 1은 아래로 2는 위로

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
