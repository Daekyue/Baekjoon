#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		int T;
		cin >> T;
		string find, target;
		cin >> find;
		cin >> target;

		int cur = 0, count = 0, tmp = 0;

		while (cur < target.size())
		{
			if (target[cur] == find[tmp])
			{
				while (target[cur + tmp] == find[tmp])
				{
					tmp++;
					if (tmp == find.size())
					{
						count++;
						break;
					}
				}
				tmp = 0;
			}
			cur++;
		}

		cout << "#" << test_case << " " << count << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}