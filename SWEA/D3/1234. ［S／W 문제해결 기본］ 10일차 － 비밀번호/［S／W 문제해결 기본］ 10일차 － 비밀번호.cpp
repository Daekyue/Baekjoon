#include <bits/stdc++.h>
using namespace std;

int main() {
	int test_case;
	int n;
	string s;
	for (test_case = 1; test_case <= 10; ++test_case) {
		cin >> n >> s;
		string result;

		for (int i = 0; i < n; i++) {
			if (!result.empty() && result.back() == s[i]) {
				result.pop_back(); // 연속된 문자 제거
			}
			else {
				result.push_back(s[i]);
			}
		}

		cout << "#" << test_case << " " << result << endl;
	}
	return 0;
}