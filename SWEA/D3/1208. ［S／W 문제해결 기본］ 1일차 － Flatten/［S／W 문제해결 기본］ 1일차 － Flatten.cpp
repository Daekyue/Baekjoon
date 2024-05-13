#include<bits/stdc++.h>

using namespace std;

int arr[100];

int main(int argc, char** argv)
{
	int test_case;

	for (test_case = 1; test_case <= 10; ++test_case)
	{
		memset(arr, 0, sizeof(arr));
		int n;
		cin >> n;

		for (int i = 0; i < 100; i++)
		{
			cin >> arr[i];
		}
		sort(arr, arr+100);

		for (int i = 0; i < n; i++)
		{
			arr[0]++;
			arr[99]--;
			sort(arr, arr + 100);
		}
		
		cout << "#" << test_case << " " << arr[99] - arr[0] <<"\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}