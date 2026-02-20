#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    int start = 1;
    int end = 1;
    int sum = 1;
    
    while (start <= n)
    {
        if(sum == n)
            answer++;
        
        if(sum >= n)
        {
            sum -= start;
            start++;
        }
        else
        {
            end++;
            sum += end;
        }
    }
    
    
    return answer;
}