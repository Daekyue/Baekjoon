// N-Queen 문제
/* 이 문제를 풀 때 퀸이 같은 대각선 상에 놓여있는지 확인하는 방법으로는
오른쪽 위에서 왼쪽 아래로 내려가는 대각선은 x+y의 값이 같으면 같은 대각선 상에 놓여있는 것이고
왼쪽 위에서 오른쪽 아래로 내려가는 대각선은 x-y의 값이 같은면 같은 대각선 상에 놓여있는 것이다*/

#include <iostream>

using namespace std;

bool isused1[40]; // 같은 열에 퀸이 위치하는지 체크 y값이 들어갈 예정
bool isused2[40]; // 대각선에 퀸이 위치하는지 체크 x+y의 값이 들어갈 예정
bool isused3[40]; // 대각선에 퀸이 위치하는지 체크 x-y의 값이 들어갈 예정
									// x-y+n-1을 할 예정 x-y의 값이 음수가 되면 안되기에
int count = 0;
int n;

void func(int current) // 현재 몇번째 행을 진행하는지 체크
{
	if(current == n)
	{
		count++;
		return;
	}
	for (int i = 0; i < n; i++)
	{
		if(isused1[i] || isused2[i+current] || isused3[current-i+n-1]) // 퀸이 놓을 수 있는 곳이 아니라면
		    continue;
		isused1[i] = 1;
		isused2[i+current] = 1;
		isused3[current-i+n-1] = 1;
		func(current+1); // 다음 행으로
		isused1[i] = 0;
		isused2[i+current] = 0;
		isused3[current-i+n-1] = 0;
	}
}

int main()
{
	cin >> n;
	func(0);
	cout << count;
}