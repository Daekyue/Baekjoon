#include<iostream>

using namespace std;
int nNum[21];
int mNum[21];
int answer;

void calM(int t, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += nNum[i] * mNum[t + i];
	}
	if (temp > answer)
		answer = temp;
}
void calN(int t, int n)
{
	int temp = 0;
	for (int i = 0; i < n; i++)
	{
		temp += mNum[i] * nNum[t + i];
	}
	if (temp > answer)
		answer = temp;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	/*freopen("input.txt", "r", stdin);*/
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int n, m;
		answer = 0;
		cin >> n >> m;
		for (int i = 0; i < n; i++)
			cin >> nNum[i];
		for (int i = 0; i < m; i++)
			cin >> mNum[i];
		if (m >= n)
		{
			for (int i = 0; i <= m - n; i++)
				calM(i, n);
		}
		else
		{
			for (int i = 0; i <= n-m; i++)
				calN(i, m);
		}


		cout << "#" << test_case << " " << answer << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}