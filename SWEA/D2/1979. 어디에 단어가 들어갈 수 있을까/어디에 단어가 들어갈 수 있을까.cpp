#include <bits/stdc++.h>

using namespace std;

int board[16][16];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, k;
		cin >> n >> k;
		int count = 0;
		int ans = 0;
		bool check = false;

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
				if (board[i][j] == 1)
				{
					count++;
				}
				else if(board[i][j] == 0 && count != 0){
					if (count == k)
						ans++;
					count = 0;
				}
			}
			if (count == k)
				ans++;
			count = 0;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (board[j][i] == 1)
					count++;
				else if (board[j][i] == 0 && count != 0) {
					if (count == k)
						ans++;
					count = 0;
				}
			}
			if (count == k)
				ans++;
			count = 0;
		}
		cout << "#" << test_case << " " << ans << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}