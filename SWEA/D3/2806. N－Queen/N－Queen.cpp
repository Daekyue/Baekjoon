#include <bits/stdc++.h>
using namespace std;

bool isused1[40];
bool isused2[40];
bool isused3[40];

int cnt;
int n;

void func(int cur)
{
    if (cur == n)
    {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isused1[i] || isused2[i + cur] || isused3[cur - i + n +1])
        	continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[cur - i + n +1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[cur - i + n +1] = 0;        
    }
}
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        cin >> n;
        func(0);
        cout << "#" << test_case<< " " << cnt << "\n";
        cnt = 0;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}