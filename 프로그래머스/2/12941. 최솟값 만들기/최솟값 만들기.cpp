#include <iostream>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int answer = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(),greater<>()); // sort함수에 greater<>() 사용시 내림차순 정렬 가능
    
    for (int i = 0; i < A.size(); i++)
    {
        answer += A[i] * B[i];
    }

    return answer;
}