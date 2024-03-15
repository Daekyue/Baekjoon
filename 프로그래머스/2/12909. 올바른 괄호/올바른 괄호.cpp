#include<string>
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;
    for(int i=0; i < s.length(); i++)
    {
        if(s[i] == '(')
            st.push('(');
        else if(s[i] == ')' && !st.empty())
            st.pop();
        else
        {
            answer = false;
            break;
        }
    }
    if(!st.empty())
        answer = false;
    return answer;
}