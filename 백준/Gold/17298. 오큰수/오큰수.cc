#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int N;
stack<int> s;
int res[1000001];
int num[1000001];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> num[i];

	for (int i = N; i >= 0; i--)
	{
		while (!s.empty() && s.top() <= num[i])
			s.pop();

		if (s.empty()) res[i] = -1;
		else res[i] = s.top();

		s.push(num[i]);
	}

	for (int i = 0; i < N; i++)
		cout << res[i] << " ";
}