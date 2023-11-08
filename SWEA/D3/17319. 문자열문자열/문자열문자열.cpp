#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        int num = 0;
        string str = "";
        cin >> num;
        cin >> str;
        cout << "#" << test_case << " ";
        if (num % 2 == 1)
        {
            cout << "No\n";
            continue;
        }
        if (str.substr(0, (num / 2)) == str.substr((num / 2), num - 1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}