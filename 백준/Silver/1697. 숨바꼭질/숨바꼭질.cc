#include <bits/stdc++.h>

using namespace std;

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int dx[3] = { 1, -1, 2 };
	int vis[200001], n, k;
	int future;
	
	cin >> n >> k;
	queue <int> Q;
	Q.push(n);
	vis[n] = 1;

	for (int i = 0; i < 200001; i++)
		vis[i] = 0;

	while (!Q.empty())
	{
		int cur = Q.front();
		if (cur == k)
		{
			cout << vis[cur];
			return 0;
		}
		Q.pop();
		for (int i = 0; i < 3; i++) {
			if (i == 2)
				future = 2 * cur;
			else
				future = cur + dx[i];
			if (future < 0 || future >= 200000) continue;
			if (vis[future]) continue;
			Q.push(future);
			vis[future] = vis[cur] + 1;
		}
	}
}

//vis를 초기화 하지 않아 오류가 발생하는 문제가 있었음