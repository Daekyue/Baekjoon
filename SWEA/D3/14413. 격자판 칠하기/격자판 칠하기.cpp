#include<bits/stdc++.h>

using namespace std;

char board[50][50];

int dx[4] = { 1, 0, -1, 0 };
int dy[4] = { 0, 1, 0, -1 };

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	bool check;
	int test_case;
	int i, j;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		check = true;
		int N, M;
		cin >> N >> M;
		char odd = 'x';
		char even = 'x';
		for (i = 0; i < N; i++)
		{
			string str;
			cin >> str;
			for (j = 0; j < M; j++)
			{
				board[i][j] = str[j];

				if (str[j] != '?')
				{
					if ((i + j) % 2 == 0)
					{
						if (even == 'x')
							even = str[j];
						if (even != 'x' && even != str[j])
							check = false;
					}
					else
					{
						if (odd == 'x')
							odd = str[j];
						if (odd != 'x' && odd != str[j])
							check = false;
					}
				}
			}
		}
		i = 0, j = 0;
		while (board[i][j] == '?')
		{
			if (j != M - 1)
				j++;
			else
			{
				j = 0;
				i++;
			}
		}
		queue <pair<int, int>> Q;
		Q.push({ i,j });
		while (!Q.empty())
		{
			pair<int, int> cur = Q.front();
			Q.pop();
			for (int i = 0; i < 4; i++)
			{
				int nx = cur.first + dx[i];
				int ny = cur.second + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= M)
					continue;
				if (board[nx][ny] == board[cur.first][cur.second])
					check = false;
				if (board[nx][ny] != '?')
					continue;
				if (board[cur.first][cur.second] == '#')
					board[nx][ny] = '.';
				else if (board[cur.first][cur.second] == '.')
					board[nx][ny] = '#';
				Q.push({ nx,ny });
			}
		}
		if (check)
			cout << "#" << test_case << " " << "possible\n";
		else
			cout << "#" << test_case << " " << "impossible\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}