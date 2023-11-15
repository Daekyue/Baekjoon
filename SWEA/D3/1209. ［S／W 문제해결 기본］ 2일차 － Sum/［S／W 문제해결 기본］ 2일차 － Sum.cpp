#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	
	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;
		int num[100][100];
		int sum[203];
		int max = 0;
		memset(num, 0, sizeof(num));
		memset(sum, 0, sizeof(sum));
		for (int i = 0; i < 100; i++)	// 행 합
		{
			for (int j = 0; j < 100; j++)
			{
				cin >> num[i][j];
				sum[i] += num[i][j];
			}
		}

		for (int i = 0; i < 100; i++)	// 열 합
		{
			for (int j = 0; j < 100; j++)
				sum[i + 100] += num[j][i];
		}

		for (int i = 0; i < 100; i++)	// 좌->우 대각선 합
			sum[201] += num[i][i];

		for (int i = 0; i < 100; i++)
			sum[202] += num[i][100 - i];
		

		for (int i = 0; i < 203; i++)
		{
			if (max < sum[i])
				max = sum[i];
		}

		cout << "#" << test_case << " " << max << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}