#include<bits/stdc++.h>

using namespace std;

int arr[102];

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		bool check = true;
		int n, m, k; // n은 손님수 m초의 시간동안 k개의 붕어빵을 만들 수 있다
		cin >> n >> m >> k;
		memset(arr, 0, sizeof(arr)); // memset(변수명, 초기화값, sizeof(변수명));
		// 손님들이 기다리는 시간없이 붕어빵을 받게 될 경우 possible
		for (int i = 0; i < n; i++)
		{
			cin >> arr[i];
		}
		int j = 0, time = 0;
		int boong = 0;
		sort(arr, arr + n);

		while (j < n)
		{
			time = arr[j];
			boong = time / m * k;
			if (boong <= j)
			{
				check = false;
				break;
			}
			j++;
		}
		if (check)
			cout << "#" << test_case << " " << "Possible" << endl;
		else
			cout << "#" << test_case << " " << "Impossible" << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}