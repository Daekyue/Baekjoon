#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

string solution(string s) {
    string answer = "";
    bool check = true;
    
    for(int i = 0; i < s.length(); i++)
    {
        if (s[i] == ' ')
        {
            check = true;
            answer = answer + s[i];
            continue;
        }
        if(check)
        {
            if('a' <= s[i] && 'z' >= s[i])
               {
                   s[i] -= 32;
               }
            answer = answer + s[i];
            check = false;
        }
        else
        {
            if('A' <= s[i] && 'Z' >= s[i])
               {
                   s[i] += 32;
               }
            answer = answer + s[i];
            check = false;
        }
    }
    return answer;
}