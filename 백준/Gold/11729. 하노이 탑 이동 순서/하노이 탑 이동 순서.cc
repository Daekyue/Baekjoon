#include <bits/stdc++.h>

using namespace std;

void move(int a, int b, int n)
{
	if (n == 1) {
		cout << a << ' ' << b << '\n';
		return;
	}
	move(a, 6 - a - b, n - 1);
	cout << a << ' ' << b << '\n';
	move(6 - a - b, b, n - 1);
}

int main(void)
{
	int num;
	cin >> num;
	cout << (1<< num) - 1 << "\n";
	move(1, 3, num);
} 