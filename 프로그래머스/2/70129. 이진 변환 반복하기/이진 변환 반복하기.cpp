#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2);
    answer.front() = 0;
    
    while(s != "1") {
        int remove_count = 0;
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '0') {
                remove_count++;
            }
        }
        answer.back() += remove_count;
        
        int num = s.length() - remove_count;
        s = "";
        while(num > 0) {
            s = to_string(num % 2) + s;
            num /= 2;
        }
        answer.front()++;
    }
    
    return answer;
}