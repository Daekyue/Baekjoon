#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    int erase = 0;
    int cnt = 0;
    
    while(s != "1")
    {
        cnt++;
        int one = 0;
        for (char i:s)
        {
            if (i=='0')
                erase++;
            else
                one++;
        }
        
        string res;
        while (one != 1)
        {
            res.push_back(char('0'+(one%2)));
            one /= 2;
        }
        res.push_back('1');
        reverse(res.begin(), res.end());
        s=res;
    }
    answer.insert(answer.begin(), cnt);
    answer.insert(answer.begin()+1, erase);
    return answer;
}