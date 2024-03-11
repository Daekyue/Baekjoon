#include <string>
#include <vector>
#include <bits/stdc++.h>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    for (int i = 1; i < n / 2 + 1; i++)
    {
        int sum = 0;
        int j = i;
        while (sum < n)
        {
            sum += j;
            j++;
        }
        if (sum == n)
            answer++;
    }
    
    return answer + 1; // 자기 자신 + 1
}