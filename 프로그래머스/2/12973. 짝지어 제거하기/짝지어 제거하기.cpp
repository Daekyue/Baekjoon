#include <iostream>
#include<string>
#include<stack>
using namespace std;

int solution(string s)
{
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        
        if (!st.empty() && st.top() == c) {
            st.pop();
        } else {
            st.push(c);
        }
    }

    return st.empty() ? 1 : 0;
}