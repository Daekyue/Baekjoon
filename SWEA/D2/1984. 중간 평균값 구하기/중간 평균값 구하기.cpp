#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int arr[10];

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
        for(int i = 0; i< 10; i++)
        {
            cin >> arr[i];
        }
        sort(arr,arr+10);
        double sum = 0;
        for(int i = 1; i <9; i++)
        {
            sum += arr[i];
        }
        double answer = round(sum/8);
        cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}