#include <bits/stdc++.h>

using namespace std;

int num[11];

int main()
{
	int n, k;
	cin >> n >> k;
	int count = 0;

	for (int i = 0; i < n; i++)
	{
		cin >> num[i];
	}
	for (int i = n - 1; i >= 0; i--)
	{
		count += k / num[i];
		k %= num[i];
	}
	cout << count;
}