#include <iostream>
#include <queue>
#include <algorithm>
#include <string>

using namespace std;

int r, c;

int arr[1002][1002];
int visitJ[1002][1002];
int visitF[1002][1002];

int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };

int main()
{
	cin >> r >> c;
	string st;

	queue<pair<int, int> > QF;
	queue<pair<int, int> > QJ;

	for (int i = 0; i < r; i++)
	{
		cin >> st;
		for (int j = 0; j < c; j++)
		{
			arr[i][j] = st[j];
			if (st[j] == 'J')
			{
				QJ.push({ i,j });
				visitJ[i][j] = 1;
			}
			else if (st[j] == 'F')
			{
				QF.push({ i,j });
				visitF[i][j] = 1;
			}
		}
	}
	while (!QF.empty())
	{
		pair<int, int> current = QF.front();
		QF.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = current.first + dx[i];
			int ny = current.second + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c)
				continue;
			if (arr[nx][ny] == '#' || visitF[nx][ny])
				continue;
			QF.push({ nx,ny });
			visitF[nx][ny] = visitF[current.first][current.second] + 1;
		}
	}
	while (!QJ.empty())
	{
		pair<int, int> current = QJ.front();
		QJ.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = current.first + dx[i];
			int ny = current.second + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) // 범위를 벗어났다 = 탈출에 성공했다
			{
				cout << visitJ[current.first][current.second]; //시작점을 1로 시작했으므로
				return 0;
			}
			if (arr[nx][ny] == '#' || visitJ[nx][ny])
				continue;
			if (visitF[nx][ny] && visitF[nx][ny] <= visitJ[current.first][current.second] + 1)
				continue;			// 지훈이의 다음 이동경로에 불이 있거나 이동과 동시에 불이 오면 이동을 못하므로 
			QJ.push({ nx,ny });
			visitJ[nx][ny] = visitJ[current.first][current.second] + 1;
		}
	}
	cout << "IMPOSSIBLE"; // return에서 탈출 못하였다는 것은 탈출할 수 없다 

}