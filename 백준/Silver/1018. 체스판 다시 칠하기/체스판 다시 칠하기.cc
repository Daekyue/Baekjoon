#include<iostream>
#include<algorithm>
#include <string>

using namespace std;

string wb[8] =
{
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW"
};
string bw[8] =
{
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB",
	"BWBWBWBW",
	"WBWBWBWB"
};

string arr[51];

int count(int x, int y, char a)
{
	int cnt_bw = 0, cnt_wb = 0;
	for (int i = 0; i < 8; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			if(a == 'b')
				if (arr[x+i][y+j] != bw[i][j])
					cnt_bw++;
			if(a == 'w')
				if (arr[x + i][y + j] != wb[i][j])
					cnt_wb++;
		}

	}
	return max(cnt_bw, cnt_wb);
}

int main(int argc, char** argv)
{
	int n, m;
	int answer = 999999;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i + 8 <= n; i++)
	{
		for (int j = 0; j + 8 <= m; j++)
		{
			int tmp;
			tmp = min(count(i, j, 'b'), count(i, j, 'w'));
			if (tmp < answer) {
				answer = tmp;
			}
		}
	}
	cout << answer;
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}