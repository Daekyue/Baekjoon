#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv)
{
	char row_check[8];
	char col_check[8];
	bool yes;
	int count;
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		for (int i = 0; i < 8; i++)
		{
			row_check[i] = 0;
			col_check[i] = 0;
		}
		yes = true;
		count = 0;

		for (int i = 0; i < 8; i++)
		{
			string str;
			cin >> str;
			for (int j = 0; j < 8; j++)
			{
				if (str[j] == 'O' && row_check[i] == 0 && col_check[j] == 0)
				{
					col_check[j] = 'o';
					row_check[i] = 'o';
					count++;
				}
				else if (str[j] == 'O' && (row_check[i] != 0 || col_check[j] != 0))
					yes = false;
			}
		}
		if (count != 8)
			yes = false;
		cout << "#" << test_case << " ";
		if (yes)
			cout << "yes" << "\n";
		else
			cout << "no" << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
