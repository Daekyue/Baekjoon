#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int num;
        cin >> num;
        int count = 0;
        for (int x = 0; x < num; x++)
        {
            for (int y = 1; y < num; y++)
            {
                if ((x * x) + (y * y) <= (num * num))
                    count++;
            }
        }
        cout << "#" << test_case << " ";
        cout << count * 4 + 5 << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
