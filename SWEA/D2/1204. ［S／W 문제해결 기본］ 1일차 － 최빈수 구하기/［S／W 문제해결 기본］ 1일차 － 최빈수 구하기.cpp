#include <bits/stdc++.h>

using namespace std;

pair<int, int> arr [100];

int main() {
	int test_case, T,n;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < 1000; i++)
		{
			int num;
			cin >> num;
			arr[num].second = num;
			arr[num].first++;
		}
		sort(arr, arr + 100, greater<>());

		cout << "#" << test_case << " " << arr[0].second << endl;
	}
	return 0;
}