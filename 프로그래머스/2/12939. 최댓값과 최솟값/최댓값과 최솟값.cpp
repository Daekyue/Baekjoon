#include <string>
#include <vector>
#include <sstream>

using namespace std;

string solution(string s) {
    string answer = "";
    stringstream ss(s);
    int num;
    int maxn = -12345678;
    int minn = 12345678;
    
    while (ss >> num)
    {
        if (maxn <= num)
            maxn = num;
        if (minn >= num)
            minn = num;
    }
    answer = to_string(minn) + " " + to_string(maxn);
    return answer;
}