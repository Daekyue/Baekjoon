#include<iostream>
#include<algorithm>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    int arr[200];
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> arr[test_case];
	}
    sort(arr, arr + 200);
    cout << arr[T/2 + 1];
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}