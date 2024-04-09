// 부분수열을 만들 때 선택지는 원소의 값을 수열에 넣을지 말지 두가지 선택지가 있다는 것을 생각하며 코드 진행
#include <iostream>

using namespace std;

int n,s, count = 0;
int arr[20];

void func(int k, int total, int cnt) // cnt는 부분수열의 안의 원소의 값을 세기 위해 넣은 값
{
	if(k == n)
	{
		if(total == s && cnt != 0) // cnt가 0이 아닐 때를 넣은 이유는 크기가 양수인 부분수열을 중에서 고르는 문제이므로 공집합을 제외하기 위해 넣었다
			count++;
		return;
	}
	func(k+1, total, cnt); // 부분수열에 값을 추가하지 않았을 경우
	func(k+1, total+arr[k], cnt+1); // 부분수열에 값을 추가하였을 경우
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> s;
	
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	
	func(0, 0, 0);
	cout << count;
}