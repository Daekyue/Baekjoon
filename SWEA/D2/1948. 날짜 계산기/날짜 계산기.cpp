#include<bits/stdc++.h>

using namespace std;

int m[13] = {0,31,28,31,30,31,30,31,31,30,31,30,31 };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int fm, fd, lm, ld;
		cin >> fm >> fd >> lm >> ld;
		int answer = 1;
		
		if (fm == lm)
			answer += ld - fd;
		else
		{
			if (ld > fd) 
			{
				for (int i = fm; i < lm; i++)
					answer += m[i];
				answer += ld - fd;
			}
			else
			{
				for (int i = fm+1; i < lm; i++)
					answer += m[i];
				answer += m[fm] - fd + ld;
			}
			
		}
			
		cout << "#" << test_case << " " << answer << "\n";
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}