#include<iostream>
#include<stack>
#include<string>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	stack<int> s;
	int count;
	string ans;

	cin >> count;
	int y = 0; //스택에 들어간 마지막 값
	while (count--) {
		int x;
		cin >> x; 
		if (x > y) {
			while (x > y) {
				s.push(++y);
				ans += '+';
			}
			s.pop();
			ans += '-'; 
		}
		else { 
			bool found = false;
			if (!s.empty()) {
				if (x == s.top()) { 
					found = true; 
				}
				s.pop();
				ans += '-';
			}
			if (!found) {
				cout << "NO" << '\n';
				return 0;
			}
		}
	}
	for (int i = 0; i < ans.length(); i++) { 
		cout << ans[i] << '\n';
	}
	return 0;
}