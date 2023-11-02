#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int board[102][102];
int vis[102][102];
string row;
int n, m;

int nx[4] = {1, 0, -1, 0};
int ny[4] = {0, 1, 0, -1};

int main(void) {
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    cin >> row;
    for (int j = 0; j < m; j++) {
      board[i][j] = row[j] - '0';
    }
  }
  queue<pair<int, int>> Q;
  Q.push({0, 0});
  vis[0][0] = 1; // 기본 BFS 구조에 1을 대입하던것 대신 해당 좌표까지 거리를 넣어준다
  while (!Q.empty()) {
    pair<int, int> cur = Q.front();
    Q.pop();
    for (int i = 0; i < 4; i++) {
      int tx = cur.X + nx[i];
      int ty = cur.Y + ny[i];
      if (tx < 0 || ty < 0 || tx >= n || ty >= m)
        continue;
      if (board[tx][ty] != 1 || vis[tx][ty])
        continue; // if문에서는 vis == 1로 체크하는 대신 vis가 0이 아니라면
                  // 넘어가는 형식으로 만들었다
      Q.push({tx, ty});
      vis[tx][ty] = vis[cur.X][cur.Y] + 1;
    }
  }
  cout << vis[n - 1][m - 1]; // n,m의 거리를 알기 위해
}