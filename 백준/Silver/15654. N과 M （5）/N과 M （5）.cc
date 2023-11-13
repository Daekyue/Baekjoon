#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10];
int num[10];

void func(int k)
{
	if (k == m)
	{
		for (int i = 0; i < m; i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!isused[i])
		{
			/*if (k > 0 && arr[k - 1] > num[i])
				continue;
			else 
			{*/
				isused[i] = 1;
				arr[k] = num[i];
				func(k + 1);
				isused[i] = 0;
			//}
		}
	}
}

int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
	{
		cin >> num[i];
		for (int j = 1; j <= n; j++)
		{
			if (num[j] > num[i])
				swap(num[j], num[i]);
		}
	}
	func(0);
}