#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    while(true){
        string s;
        getline(cin, s);
        if(s == ".") break;
        stack<char> st;
        bool check = true;
        for (int i = 0; i< s.length(); i++)
		{
			char c = s[i];
            if(c == '(' || c == '[')
                st.push(c);
            else if(c == ')')
            {
                if(st.empty() || st.top() != '(')
                {
                    check = false;
                    break;
                }
                st.pop();
            }
            else if(c == ']')
            {
                if(st.empty() || st.top() != '[')
                {
                    check = false;
                    break;
                }
                st.pop();
            }
        }
        if(!st.empty()) check = false;
        if(check) cout << "yes\n";
        else cout << "no\n";
    }
}