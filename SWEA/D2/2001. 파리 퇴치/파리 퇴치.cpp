#include <bits/stdc++.h>

using namespace std;

int board[300][300];


int main(void)
{
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		int n, m;
		cin >> n >> m;
		int mx = 0;
		int sum = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> board[i][j];
			}
		}
		for (int i = 0; i < n - m+1; i++)
		{
			for (int j = 0; j < n-m+1; j++)
			{
				for(int k = 0; k < m; k++)
					for (int h = 0; h <m; h++)
						sum += board[i+k][j+h];
				mx = max(sum, mx);
				sum = 0;
			}
		}
		cout << "#" << test << " " << mx << "\n";
	}
}