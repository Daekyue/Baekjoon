#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;

    for (int ii = 0; ii < commands.size(); ii++)
    {
        int i = commands[ii][0];
        int j = commands[ii][1];
        int k = commands[ii][2];
        vector<int> temp;

        for (int kk = i-1; kk < j; kk++)
        {
            temp.push_back(array[kk]);
        }
        sort(temp.begin(), temp.end());
        answer.push_back(temp[k-1]);
    }
    
    return answer;
}