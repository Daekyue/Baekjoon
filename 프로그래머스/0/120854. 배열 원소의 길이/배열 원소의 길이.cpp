#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size()); // answer 벡터 크기 설정

    for (int i = 0; i < strlist.size(); i++) { // strlist.size()로 수정
        int count = 0;
        while (strlist[i][count] != '\0') // '\n'을 '\0'로 수정
            count++;
        answer[i] = count;
    }

    return answer;
}