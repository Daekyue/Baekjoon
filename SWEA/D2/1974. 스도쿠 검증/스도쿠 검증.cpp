#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int arr[10][10];

// 행의 중복 검사 함수
bool checkRow() {
    for (int i = 0; i < 9; ++i) {
        vector<bool> visited(10, false); 
        for (int j = 0; j < 9; ++j) {
            if (visited[arr[i][j]]) 
                return false;
            visited[arr[i][j]] = true;
        }
    }
    return true; 
}

// 열의 중복 검사 함수
bool checkColumn() {
    for (int j = 0; j < 9; ++j) {
        vector<bool> visited(10, false); 
        for (int i = 0; i < 9; ++i) {
            if (visited[arr[i][j]]) 
                return false;
            visited[arr[i][j]] = true;
        }
    }
    return true; 
}

// 3x3 작은 정사각형 영역의 중복 검사 함수
bool checkSquare() {
    for (int row = 0; row < 9; row += 3) {
        for (int col = 0; col < 9; col += 3) {
            vector<bool> visited(10, false); 
            for (int i = row; i < row + 3; ++i) {
                for (int j = col; j < col + 3; ++j) {
                    if (visited[arr[i][j]]) 
                        return false;
                    visited[arr[i][j]] = true;
                }
            }
        }
    }
    return true; 
}

int main(int argc, char** argv) {
    int T;
    cin >> T;

    for (int test_case = 1; test_case <= T; ++test_case) {
        // 스도쿠 판 입력 받기
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                cin >> arr[i][j];
            }
        }

        bool isValid = checkRow() && checkColumn() && checkSquare();
        int answer = 1;
        if (!isValid)
            answer = 0;
        cout << "#" << test_case << " " << answer << "\n";
    }
    return 0; // 정상 종료
}