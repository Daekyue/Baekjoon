#include<bits/stdc++.h>

using namespace std;

char arr[8][8];

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int count = 0;
		int n;
		cin >> n;

		string s;
		for (int i = 0; i < 8; i++)
		{
			cin >> s;
			for (int j = 0; j < 8; j++)
			{
				arr[i][j] = s[j];
			}
		}

		// 가로 비교
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - n; j++)
			{
				bool check = true;
				for (int k = 0; k < n / 2; k++) 
				{
					if (arr[i][j + k] != arr[i][j + n - k - 1]) // j + n - k - 1 = n의 길이만큼의 회문이기에 제일 끝값부터 비교, 배열을 사용하였기에 idx값을 생각하여 -1, -k는 뒤에서 오는 값 투포인터로 풀어도 될 듯
					{
						check = false;
						break;
					}
				}
				if (check)
					count++;
			}
		}

		// 세로 비교
		for (int i = 0; i < 8; i++)
		{
			for (int j = 0; j <= 8 - n; j++)
			{
				bool check = true;
				for (int k = 0; k < n / 2; k++)
				{
					if (arr[j + k][i] != arr[j + n - k - 1][i])
					{
						check = false;
						break;
					}
				}
				if (check)
					count++;
			}
		}
		cout << "#" << test_case << " " << count << endl;
	}
	return 0; // 정상종료시 반드시 0을 리턴해야합니다.
}