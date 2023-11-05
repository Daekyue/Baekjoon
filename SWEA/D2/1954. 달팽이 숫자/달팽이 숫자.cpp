#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	int N;
	
	int board[10][10];
	cin >> T;

	int dx[4] = { 0, 1, 0, -1 };
	int dy[4] = { 1, 0, -1, 0 };
	
	for (test_case = 1; test_case <= T; ++test_case)
	{	
		int num = 1;
		int dist = 0;
		int x = 0, y = 0;
		cin >> N;
		cout << "#" << test_case << "\n";

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				board[i][j] = 0;
		board[0][0] = num;
		while (num != N * N)
		{
			num++;
			x = x + dx[dist % 4];
			y = y + dy[dist % 4];
			if (x < 0 || y < 0 || x >= N || y >= N || board[x][y] != 0)
			{if(num==6)
			{
				num = 6;
			}
				x = x - dx[dist % 4];
				y = y - dy[dist % 4];
				dist++;
				num--;
			}
			board[x][y] = num;
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
				cout << board[i][j] << " ";
			cout << "\n";
		}
	}

	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}