#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
#define X first
#define Y second

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 }; // 남쪽, 동쪽, 북쪽, 서쪽 순서
int n, m;
int board1[10][10]; // 최초에 입력받은 board를 저장할 변수
int board2[10][10]; // 사각 지대의 개수를 세기 위해 사용할 변수
vector<pair<int, int> > cctv; // cctv의 좌표를 저장할 변수
int answer;

bool OOB(int a, int b) { // Out Of Bounds 확인
	return a < 0 || a >= n || b < 0 || b >= m;
}

// (x,y)에서 dir 방향으로 진행하면서 벽을 만날 때 까지 지나치는 모든 빈칸을 7로 바꿔버림
void upd(int x, int y, int dir) {
	dir %= 4;
	while (1) {
		x += dx[dir];
		y += dy[dir];
		if (OOB(x, y) || board2[x][y] == 6) return; // 범위를 벗어났거나 벽을 만나면 함수를 탈출
		if (board2[x][y] != 0) continue; // 해당 칸이 빈칸이 아닐 경우(=cctv가 있을 경우) 넘어감
		board2[x][y] = 7; // 빈칸을 7로 덮음
	}
}

void func(int k)
{
	if (k == cctv.size())
	{
		int val = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				val += (board2[i][j] == 0);
		answer = min(answer, val);

		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int tmp[10][10];
		for (int a = 0; a < n; a++)
			for (int b = 0; b < m; b++)
				tmp[a][b] = board2[a][b]; // 원본 보드를 저장해두고

		int x = cctv[k].X;
		int y = cctv[k].Y;
		if (board1[x][y] == 1) {
			upd(x, y, i);
		}
		else if (board1[x][y] == 2) {
			upd(x, y, i);
			upd(x, y, i + 2);
		}
		else if (board1[x][y] == 3) {
			upd(x, y, i);
			upd(x, y, i + 1);
		}
		else if (board1[x][y] == 4) {
			upd(x, y, i);
			upd(x, y, i + 1);
			upd(x, y, i + 2);
		}
		else { // board1[x][y] == 5
			upd(x, y, i);
			upd(x, y, i + 1);
			upd(x, y, i + 2);
			upd(x, y, i + 3);
		}
		func(k + 1);

		for (int a = 0; a < n; a++)
			for (int b = 0; b < m; b++)
				board2[a][b] = tmp[a][b]; // 다음 방향을 탐색하기 전에 보드를 복구
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board1[i][j];
			if (board1[i][j] != 0 && board1[i][j] != 6)
				cctv.push_back({ i,j });
			if (board1[i][j] == 0) answer++; // 0이 다 사각지대인것이 최대 정답 여기서 이제 줄여나감
		}
	}
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			board2[i][j] = board1[i][j];
	func(0);
	cout << answer;
}