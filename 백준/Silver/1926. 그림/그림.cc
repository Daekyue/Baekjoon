#include <bits/stdc++.h>
using namespace std;

#define X first
#define Y second

int main(void) {
  int board[502][502];
  int vis[502][502];
  int dx[4] = {1, 0, -1, 0};
  int dy[4] = {0, 1, 0, -1};
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      cin >> board[i][j];
    }
  }

  queue<pair<int, int>> Q;

  int size;
  int max_size = 0;
  int count = 0;

  for (int xi = 0; xi < n; xi++) {
    for (int yi = 0; yi < m; yi++) {
      if (board[xi][yi] == 1) {
        size = 0;
        Q.push({xi, yi});
        vis[xi][yi] = 1;
        board[xi][yi] = 0;
        while (!Q.empty()) {
          size++;
          pair<int, int> cur = Q.front();
          Q.pop();
          for (int i = 0; i < 4; i++) {
            int nx = cur.X + dx[i];
            int ny = cur.Y + dy[i];
            if (nx >= n || ny >= m || nx < 0 || ny < 0)
              continue;
            if (board[nx][ny] != 1 || vis[nx][ny] == 1)
              continue;
            Q.push({nx, ny});
            vis[nx][ny] = 1;
            board[nx][ny] = 0;
          }
        }
        if (size > max_size)
          max_size = size;
        count++;
      }
    }
  }
  cout << count << "\n" << max_size;
}