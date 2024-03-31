#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> strlist) {
    vector<int> answer(strlist.size());
    
    for (int i = 0; i < strlist.size(); i++) {
        int count = 0;
        while (strlist[i][count] != '\0') 
            count++;
        answer[i] = count;
    }

    return answer;
}