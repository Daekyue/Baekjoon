#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[10];
bool isused[10];

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
		//if (!isused[i])
		//{
			if (k > 0 && arr[k - 1] > i)
				continue;
			else 
			{
				//isused[i] = 1;
				arr[k] = i;
				func(k + 1);
				//isused[i] = 0;
			}
		//}
	}
}

int main(void)
{
	cin >> n >> m;
	func(0);
}