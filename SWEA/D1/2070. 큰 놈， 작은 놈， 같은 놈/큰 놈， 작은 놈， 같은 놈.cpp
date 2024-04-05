#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num1, num2;
        cin >> num1 >> num2;
        if(num1 > num2)
            cout <<"#" << test_case << " >" << endl;
        else if(num1 == num2)
            cout <<"#" << test_case << " =" << endl;
        else
            cout <<"#" << test_case << " <" << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}