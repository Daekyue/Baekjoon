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
        else if(s[i] == ')' && !st.empty()) // )가 입력 되었는데 비어있을 경우 짝이 맞지 않으므로 false
            st.pop();
        else
        {
            answer = false;
            break;
        }
    }
    if(!st.empty()) // 비어있지 않을 경우 짝이 맞지 않는 것이므로 false
        answer = false;
    return answer;
}
