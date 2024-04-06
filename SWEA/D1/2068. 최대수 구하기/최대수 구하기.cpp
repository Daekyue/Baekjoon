#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin>>T;
    
	for(test_case = 1; test_case <= T; ++test_case)
	{
        int num, max = 0;
        for(int i = 0; i < 10; i++)
        {
            cin >> num;
            if(num > max)
                max = num;
        }
        
        cout << "#" << test_case << " " << max << endl;
	}
	return 0;
}