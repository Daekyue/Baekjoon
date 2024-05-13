#include<bits/stdc++.h>

using namespace std;

int arr[100][100];

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;
		memset(arr, 0, sizeof(arr));
		int maxSum = 0, crossSum = 0;

		// 가로합 중 가장 큰 것
		for (int i = 0; i < 100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				cin >> arr[i][j];
				sum += arr[i][j];
			}
			maxSum = max(maxSum, sum);
		}

		// 세로합 중 가장 큰 것
		for (int i = 0; i < 100; i++)
		{
			int sum = 0;
			for (int j = 0; j < 100; j++)
			{
				sum += arr[j][i];
			}
			maxSum = max(maxSum, sum);
		}

		for (int i = 0; i < 100; i++)
		{
			crossSum += arr[i][i];
		}
		maxSum = max(maxSum, crossSum);

		crossSum = 0;
		for (int i = 99; i >= 0; i--)
		{
			crossSum += arr[99-i][i];
		}
		maxSum = max(maxSum, crossSum);

		cout << "#" << test_case << " " << maxSum <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}