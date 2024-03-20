#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer(2);
    int area = brown + yellow;
    int height, width;
    
    for (height = 3; height < area / 2; height++)
    {
        if(area % height == 0)
        {
            width = area / height;
            if(2 * (width+height) - 4 == brown)
            {
                answer.front() = width;
                answer.back() = height;
                break;
            }
        }
    }
    
    return answer;
}