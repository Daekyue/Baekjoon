#include <bits/stdc++.h>

using namespace std;

int arr[102][102];

int main(int argc, char** argv)
{
	int test_case;
	int T = 10;
	
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N;
		cin >> N;
		int answer = 0;
		for (int i = 0; i < 100; i++)
		{
			for (int j = 0; j < 100; j++)
				cin >> arr[i][j];
		}

		for (int row = 0; row < 100; row++)
		{
			bool check = false;
			for (int col = 0; col < 100; col++)
			{
				if (arr[col][row] == 1)
				{
					check = true;
				}
				else if (arr[col][row] == 2)
				{
					if (check)
					{
						++answer;
						check = false;
					}
				}
			}
		}
		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}