#include <bits/stdc++.h>

using namespace std;

int num[8];
int temp[8];

void cal()
{
	for (int i = 1; i <= 5; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			temp[j] = num[j + 1];
		}
		temp[7] = num[0] - i;
		if (temp[7] <= 0)
		{
			temp[7] = 0;
			for (int k = 0; k < 8; k++)
			{
				num[k] = temp[k];
			}
			return;
		}
		for (int k = 0; k < 8; k++)
		{
			num[k] = temp[k];
		}
	}
	return;
}

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		memset(num, 0, sizeof(num));
		int T;
		cin >> T;

		for (int i = 0; i < 8; i++)
		{
			cin >> num[i];
		}
		while (num[7] != 0)
		{
			cal();
		}
		cout << "#" << test_case;
		for (int k = 0; k < 8; k++)
		{
			cout << " " << num[k];
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

