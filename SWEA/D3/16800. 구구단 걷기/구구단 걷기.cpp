#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        long long int num = 0;
        cin >> num;
        long long int ans = num - 1;
        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0 && ans > (i -1) + (num / i - 1))
                ans = (i - 1) + (num / i - 1);
        }
        cout << "#" << test_case << " " << ans << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}