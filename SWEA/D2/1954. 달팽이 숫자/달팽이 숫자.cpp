#include<bits/stdc++.h>

using namespace std;

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0, 1, 0, -1};
int arr[11][11];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;
		int nx = 0, ny = 0;
		int num = 0;
		for (int i = 1; i <= n*n; i++)
		{
			arr[ny][nx] = i;
			ny += dy[num%4];
			nx += dx[num % 4];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n || arr[ny][nx] != 0)
			{
				ny -= dy[num % 4];
				nx -= dx[num % 4];

				num++;

				ny += dy[num % 4];
				nx += dx[num % 4];
			}
		}

		cout << "#" << test_case << "\n";
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				cout << arr[i][j] << " ";
			cout << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}