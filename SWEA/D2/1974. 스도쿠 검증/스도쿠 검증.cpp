#include<iostream>

using namespace std;

int arr[10][10];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	//freopen("input.txt", "r", stdin);
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int answer = 1;
		for (int i = 0; i < 9; i++)
		{
			int check = 0;
			for (int j = 0; j < 9; j++)
			{
				cin >> arr[i][j];
				check += arr[i][j];
			}
			if (check != 45)
			{
				answer = 0;
			}
		}

		// 세로 검증
		if (answer)
		{
			for (int i = 0; i < 9; i++)
			{
				int check = 0;
				for (int j = 0; j < 9; j++)
					check += arr[j][i];
				if (check != 45)
				{
					answer = 0;
					break;
				}
			}
		}

		// 세로 검증
		if (answer)
		{
			for (int i = 0; i < 9; i++)
			{
				int check = 0;
				for (int j = 0; j < 9; j++)
					check += arr[j][i];
				if (check != 45)
				{
					answer = 0;
					break;
				}
			}
		}

		//3*3 검증
		if (answer)
		{
			int dx[9]{ -1, -1, -1, 0,0,0, 1,1,1 };
			int dy[9]{ -1,0,1,-1,0,1,-1,0,1};

			for (int i = 1; i < 9; i += 3)
			{
				for (int j = 1; j < 9; j += 3)
				{
					int check = 0;
					for (int k = 0; k < 9; k++)
					{
						check += arr[i + dx[k]][j + dy[k]];
					}
					if (check != 45)
					{
						answer = 0;
						break;
					}
				}
				if (!answer)
					break;
			}

		}

		cout << "#" << test_case << " " << answer << "\n";

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
