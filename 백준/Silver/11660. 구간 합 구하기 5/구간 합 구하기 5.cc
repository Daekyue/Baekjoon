#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int n,m,x1,x2,y1,y2;
	
	cin >> n >> m;
	
	vector<vector<int>> A(n+1, vector<int>(n + 1, 0)); // vector의 타입으로 vector<int>를 
																										//선언하여 2차원 배열 생성, 0으로 초기화된 n+1 크기의 vector를 생성
	vector<vector<int>> D(n+1, vector<int>(n + 1, 0));
	
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			cin >> A[i][j];
			D[i][j] = D[i-1][j] + D[i][j-1] - D[i-1][j-1] + A[i][j];
		}
	}
	
	for (int i = 0; i < m; i++)
	{
		cin >> x1 >> y1 >> x2 >> y2;
		cout << D[x2][y2] - D[x1-1][y2] - D[x2][y1-1] + D[x1-1][y1-1] << "\n";
	}
}