#include <bits/stdc++.h>

using namespace std;

int arr[100];
int decode[10][4] = 
{ {3,2,1,1},{2,2,2,1},{2,1,2,2},{1,4,1,1},{1,1,3,2},
  {1,2,3,1},{1,1,1,4},{1,3,1,2},{1,2,1,3},{3,1,1,2} };
int solve[4];
int solveNumArr[8];

int main() {
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case) {
		int n, m;
		cin >> n >> m;

		vector<string> lines(n);
		for (int i = 0; i < n; i++) {
			cin >> lines[i];
		}

		// 1이 포함된 마지막 줄에서 암호코드 추출
		string str;
		for (int i = n - 1; i >= 0; i--) {
			if (lines[i].find('1') != string::npos) {
				str = lines[i];
				break;
			}
		}

		// 암호코드 끝부분부터 탐색
		int pos = str.rfind('1');
		pos -= 55; // 암호코드는 56자리이므로, 처음 1이 나온 곳에서 55칸 앞으로 이동

		for (int i = 0; i < 56; i++) {
			arr[i] = str[pos + i] - '0';
		}

		// 코드 해독
		int num = 0;
		for (int i = 0; i < 8; i++) {
			memset(solve, 0, sizeof(solve));
			int solveNum = 0;
			for (int j = 0; j < 7; j++) {
				solve[solveNum]++;
				if (j < 6 && arr[(i * 7) + j] != arr[(i * 7) + j + 1])
					solveNum++;
			}
			int rowIndex = 0;
			for (int k = 0; k < 10; k++) {
				bool match = true;
				for (int l = 0; l < 4; l++) {
					if (decode[k][l] != solve[l]) {
						match = false;
						break;
					}
				}
				if (match) {
					rowIndex = k;
					break;
				}
			}
			solveNumArr[i] = rowIndex;
		}

		int answer = 0, sum = 0;
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0)
				sum += (solveNumArr[i] * 3);
			else
				sum += solveNumArr[i];
			answer += solveNumArr[i];
		}
		if (sum % 10 != 0)
			answer = 0;

		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;
}
