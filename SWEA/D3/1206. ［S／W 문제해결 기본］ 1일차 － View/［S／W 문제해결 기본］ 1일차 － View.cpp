#include<bits/stdc++.h>

using namespace std;

int arr[1000];

int comp[4] = { -2, -1, 1, 2 };

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		int answer = 0;
		for (int i = 2; i < n - 2; i++)
		{
			bool check = true;
			int tall = 0;
			for (int j = 0; j < 4; j++)
			{
				if (arr[i] <= arr[i + comp[j]])
				{
					check = false;
					break;
				}
				tall = max(tall, arr[i + comp[j]]);
			}
			if (check)
				answer += arr[i] - tall;
			tall = 0;
		}

		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}