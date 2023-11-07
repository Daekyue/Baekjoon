#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;

    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string str;
        cin >> str;
        string copy;
        copy += str[0];
        for (int i = 1; i < str.length(); i++)
        {   
            if (str[0] != str[i] || str.substr(i, copy.length()) != copy)
                copy += str[i];
            else
                break;
        }
        cout << "#" << test_case << " ";
        cout << copy.length() << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}
