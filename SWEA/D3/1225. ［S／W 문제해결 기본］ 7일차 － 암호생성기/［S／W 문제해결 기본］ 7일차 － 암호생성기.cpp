#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	ios::sync_with_stdio(0);
	cin.tie(NULL);
	cout.tie(NULL);
	int test_case;
	int T;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		deque<int> dq(8);

		for (int i = 0; i < 8; i++)
		{	
			cin >> dq[i];
		}
		while (dq.back() != 0)
		{
			for (int i = 1; i <= 5; i++)
			{
				int num = dq.front() - i;
				dq.pop_front();
				dq.push_back(num);
				if (dq.back() <= 0)
				{
					dq.back() = 0;
					break;
				}
			}
		}
		
		cout << "#" << test_case << " ";
		for (int i = 0; i < 8; i++)
		{
			cout << dq[i] << " ";
		}
		cout << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}