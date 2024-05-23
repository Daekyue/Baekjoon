#include <string>
#include <vector>
#include <deque>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = 0;
    deque<char> dq(s.begin(), s.end());
    
    for (int j = 0; j < s.length(); j++) {
        stack<char> st;
        bool check = true;
        
        for (int i = 0; i < s.length(); i++) {
            if (dq[i] == '(' || dq[i] == '{' || dq[i] == '[') {
                st.push(dq[i]);
            } else {
                if (!st.empty() && 
                    ((dq[i] == ')' && st.top() == '(') || 
                     (dq[i] == '}' && st.top() == '{') || 
                     (dq[i] == ']' && st.top() == '['))) {
                    st.pop();
                } else {
                    check = false;
                    break;
                }
            }
        }
        
        if (check && st.empty()) {
            answer++;
        }
        
        dq.push_back(dq.front());
        dq.pop_front();
    }
    
    return answer;
}
