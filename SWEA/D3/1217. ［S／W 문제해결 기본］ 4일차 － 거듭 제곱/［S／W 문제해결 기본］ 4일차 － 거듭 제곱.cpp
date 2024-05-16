#include <iostream>

using namespace std;

int n, m, answer;

void func(int base, int k)
{
	if (k == m + 1)
		return;
	answer *= n;
	func(n, k + 1);
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		cin >> T;
		cin >> n >> m;
		answer = 1;
		func(n, 1);

		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}