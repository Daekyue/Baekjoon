#include<iostream>
#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int sum = 0; 
        double avg = 0;
        for (int i = 0; i < 10; i++)
        {
            cin >> sum;
            avg += sum;
        }
        cout <<"#" << test_case<< " "<< round((avg/10)) << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}