#include<bits/stdc++.h>

using namespace std;

int board[1002][1002];
int vis[1002][1002];
int n, m;
int bx[4] = { 1, 0, -1, 0 };
int by[4] = { 0, 1, 0, -1 };


int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	int max = 0;

	queue <pair<int, int>> Q;
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> board[i][j];
			if (board[i][j] == 1)
			{
				Q.push({ i,j });
				vis[i][j] = 1;
			}
			else if (board[i][j] == -1)
				vis[i][j] = -1;
		}
	}
	while (!Q.empty()) 
	{
		pair<int, int> cur = Q.front();
		Q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = cur.first + bx[i];
			int ny = cur.second + by[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (board[nx][ny] == -1 || vis[nx][ny])
				continue;
			Q.push({ nx, ny });
			vis[nx][ny] = vis[cur.first][cur.second] + 1;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (max < vis[i][j])
				max = vis[i][j];
			else if (vis[i][j] == 0 && board[i][j] != -1)
			{
				cout << "-1";
				return 0;
			}
		}
	}
	cout << max - 1;
}