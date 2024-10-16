#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int timeToSeconds(const string& time) {
    int minutes = stoi(time.substr(0, 2));
    int seconds = stoi(time.substr(3, 2));
    return minutes * 60 + seconds;
}

// 초 단위의 시간을 "mm:ss" 형식으로 변환 (문자열 직접 조작)
string secondsToTime(int totalSeconds) {
    int minutes = totalSeconds / 60;
    int seconds = totalSeconds % 60;
    
    // 결과를 담을 문자열
    string result = "";
    
    // 분이 10보다 작은 경우 앞에 '0'을 붙임
    if (minutes < 10) result += "0";
    result += to_string(minutes) + ":";
    
    // 초가 10보다 작은 경우 앞에 '0'을 붙임
    if (seconds < 10) result += "0";
    result += to_string(seconds);
    
    return result;
}

string solution(string video_len, string pos, string op_start, string op_end, vector<string> commands) {
    // 각 시간 문자열을 초 단위로 변환
    int videoLen = timeToSeconds(video_len);
    int currentPos = timeToSeconds(pos);
    int opStart = timeToSeconds(op_start);
    int opEnd = timeToSeconds(op_end);
    
    if (opStart <= currentPos && currentPos <= opEnd)
        currentPos = opEnd;

    // 명령어에 따라 위치 조정
    for (const string& command : commands) {
        if (command == "prev") {
            // 10초 전으로 이동
            currentPos = max(0, currentPos - 10);
        } else if (command == "next") {
            // 10초 후로 이동
            currentPos = min(videoLen, currentPos + 10);
        }

        // 오프닝 구간일 경우 오프닝 끝으로 이동
        if (opStart <= currentPos && currentPos <= opEnd) {
            currentPos = opEnd;
        }
    }

    // 최종 위치를 "mm:ss" 형식으로 변환하여 반환
    return secondsToTime(currentPos);
}