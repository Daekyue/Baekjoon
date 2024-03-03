#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    stringstream ss(s);
    int min_num = 2147483647;
    int max_num = -2147483648;
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