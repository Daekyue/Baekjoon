#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer(2);
    unordered_map<string, int> check;
    int i = 1;
    check[words[0]] = 1;
    
    for (i; i < words.size(); i++)
    {
        if(check[words[i]] || words[i-1][words[i-1].size() - 1] != words[i][0]) // 앞단어의 끝 글자와 시작 글자가 같지 않을 경우
        {
            answer[0] = (i % n) + 1;
            answer[1] = (i / n) + 1;
            break;
        }
        check[words[i]] = 1;
    }
    if (i == words.size())
    {
        answer[0] = 0;
        answer[1] = 0;
    }

    return answer;
}
