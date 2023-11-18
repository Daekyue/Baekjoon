#include <bits/stdc++.h>

using namespace std;

int n, l;
int num[20];
int cal[20];
int ans;

void dfs(int start, int current, int point) 
{
	if (start == n)
	{
		return;
	}
	for (int i = start + 1; i < n; i++)
	{
		if (current + cal[i] <= l)
		{
			ans = max(ans, point + num[i]);
			dfs(i, current + cal[i], point + num[i]);
		}
	}
}

int main()
{
	int T;
	cin >> T;
	for (int test = 1; test <= T; test++)
	{
		ans = 0;
		cin >> n >> l;
		for (int i = 0; i < n; i++)
			cin >> num[i] >> cal[i];
		for (int i = 0; i < n; i++)
			dfs(i, cal[i], num[i]);
		cout << "#" << test << " " << ans << "\n";
	}
}