#include <bits/stdc++.h>

using namespace std;

int arr[20];
int dp[100000];

int main()
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		memset(dp, 0, sizeof(dp));
		memset(arr, 0, sizeof(arr));
		int n, k;
		cin >> n >> k;
		for (int i = 0; i < n; i++)
			cin >> arr[i];
		dp[0] = 1;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += arr[i];
			for (int j = sum; j >= 0; j--)
			{
				if (dp[j])
					dp[j + arr[i]] += dp[j];
			}
		}
		cout << "#" << test_case << " " << dp[k] << "\n";
	}
}