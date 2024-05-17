#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int test_case;
	for (test_case = 1; test_case <= 10; ++test_case) 
	{
		int n;
		string str, result;
		cin >> n >> str;
		result.push_back(str[0]);

		for (int i = 1; i < n; i++)
		{
			if (result.back() != str[i])
				result.push_back(str[i]);
			else if (result.back() == str[i])
				result.pop_back();
		}

		cout << "#" << test_case << " " << result << "\n";
	}
	return 0;
}
