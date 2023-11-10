#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv)
{
    int test_case;
    int T;
    cin >> T;
    for (test_case = 1; test_case <= T; ++test_case)
    {
        string st;
        string stt;
        cin >> st;
        cin >> stt;
        
        if(st.length() != stt.length())
        {
            int a = st.length();
            int b = stt.length();
            int num = 1;	// 최소공배수
            int i = 2;
            while ( (a != i && b != i) && ( a != 1 && b != 1))
            {
                if (a % i != 0 || b% i != 0)
                    i++;
                else
                {
                    num *= i;
                    a /= i;
                    b /= i;
                    i=2;
                }
            }
            num = num * a * b;
            a = st.length();
            b = stt.length();
            i = 0;
            while (st.length() != num)
            {
                st += st[i % a];
                i++;
            }
             i = 0;
            while (stt.length() != num)
            {
                stt += stt[i % b];
                i++;
            }
        }
        if(st == stt)
            cout << "#" << test_case << " " << "yes" << "\n";
        else
            cout << "#" << test_case << " " << "no" << "\n";
    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}