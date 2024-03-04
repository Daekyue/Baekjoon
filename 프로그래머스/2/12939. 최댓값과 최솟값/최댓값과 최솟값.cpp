#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int min_num = 2147483647;        // int 범위 중 최댓값을 min 값으로 설정하여 어떤 값이 들어오더라도 최소값이 변경되게 설정
    int max_num = -2147483648;        // int 범위 중 최소값을 max 값으로 설정하여 어떤 값이 들어오더라도 최대값이 변경되게 설정
    int num;
    
    while (ss >> num) {
        if (num < min_num) {
            min_num = num;
        }
        if (num > max_num) {
            max_num = num;
        }
    }
    
    return to_string(min_num) + " " + to_string(max_num);
}
