#include <bits/stdc++.h>

using namespace std;

long long int price[1000002];

int main(void)
{
	int t;
	cin >> t;
	for (int test = 1; test <= t; test++)
	{
		int n;
		long long ans = 0;

		cin >> n;
		memset(price, 0, sizeof(price));
		for (int i = 0; i < n; i++)
		{
			cin >> price[i];
		}
		int mx = price[n - 1];
		
		for (int i = n - 1; i >= 0; i--)
		{
			if (mx >= price[i])
			{
				ans += mx - price[i];
			}
			else
				mx = price[i];
		}
		cout << "#" << test << " " << ans << "\n";
	}
}