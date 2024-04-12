#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int arr[16][2];
int maxProfit = 0;

void backtrack(int day, int profit) {
	if (day > n) { //퇴사일을 지나면 종료
		maxProfit = max(maxProfit, profit);
		return;
	}

	// 현재 상담을 선택하고 다음 상담을 탐색
	if (day + arr[day][0] <= n + 1) { // 상담을 할 수 있는지 확인
		backtrack(day + arr[day][0], profit + arr[day][1]);
	}

	// 현재 상담을 선택하지 않고 다음 상담을 탐색
	backtrack(day + 1, profit);
}

int main() {
	ios::sync_with_stdio(false);
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> arr[i][0] >> arr[i][1];
	}

	backtrack(1, 0); // 첫째 날부터 시작

	cout << maxProfit << endl;

	return 0;
}