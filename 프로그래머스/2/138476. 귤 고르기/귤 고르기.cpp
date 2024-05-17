#include <bits/stdc++.h>

using namespace std;

vector<int> arr(10000001);

int solution(int k, vector<int> tangerine) {
    int answer = 0;
    for(int i : tangerine)
    {
        arr[i]++;
    }
    sort(arr.begin(),arr.end(),greater<>());
    int sum = 0;
    for(int i = 0; i < arr.size(); i++)
    {
        if(sum >= k)
        {
            answer = i;
            break;
        }
        sum += arr[i];
    }
    return answer;
}