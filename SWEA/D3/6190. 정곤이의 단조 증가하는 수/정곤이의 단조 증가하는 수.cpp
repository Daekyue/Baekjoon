#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int ans, n;
string s;

int arr[1002];
int check[2];

void func(int k, int kk)
{
	if (k == 2)
	{
		bool ch = true;
		string chk = to_string(check[0] * check[1]);
		for (int i = 0; i < chk.size(); i++)
		{
			if (chk[i] > chk[i + 1] && chk[i + 1] != NULL)
			{

				ch = false;
				break;
			}
		}
		if (ch)
			ans = max(check[0] * check[1], ans);
		return;
	}
	for (int i = 1; i <= n; i++)
	{
		if (i > kk)
		{
			check[k] = arr[i];
			func(k + 1, i);
			check[k] = 0;
		}
	}
}

int main(void)
{
	int t;
	cin >> t;

	for (int i = 1; i <= t; i++)
	{
		ans = -1;
		cin >> n;
		for (int j = 1; j <= n; j++)
		{
			cin >> arr[j];
		}
		func(0, 0);
		cout << "#" << i << " " << ans << endl;
	}
	return 0;
}