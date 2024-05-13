#include<bits/stdc++.h>

using namespace std;

char arr[11][11];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(arr, ' ', sizeof(arr));
		int n;
		cin >> n;
		
		int col = 0, row = 0;
		for (int i = 0; i < n; i++)
		{
			int num;
			char c;
			cin >> c >> num;

			for (int j = 0; j < num; j++)
			{
				arr[col][row] = c;
				row++;
				if (row >= 10)
				{
					row = 0;
					col++;
				}
			}

		}
		cout << "#" << test_case << "\n";
		for (int i = 0; i <= col; i++)
		{
			for (int j = 0; j < 10; j++)
			{
				cout << arr[i][j];
			}
			cout << "\n";
		}
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}