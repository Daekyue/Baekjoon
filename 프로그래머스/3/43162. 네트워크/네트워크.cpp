#include <vector>
using namespace std;

// DFS를 사용하여 연결된 모든 컴퓨터를 방문하는 함수
void dfs(int node, vector<vector<int>>& computers, vector<bool>& visited, int n) {
    visited[node] = true;  // 현재 노드를 방문 처리
    for (int i = 0; i < n; ++i) {
        // 연결되어 있고 아직 방문하지 않은 노드가 있으면 DFS 재귀 호출
        if (computers[node][i] == 1 && !visited[i]) {
            dfs(i, computers, visited, n);
        }
    }
}

int solution(int n, vector<vector<int>> computers) {
    vector<bool> visited(n, false);  // 각 컴퓨터의 방문 여부를 기록할 배열
    int answer = 0;  // 네트워크 개수

    // 모든 컴퓨터를 확인하며 DFS 수행
    for (int i = 0; i < n; ++i) {
        // 만약 아직 방문하지 않았다면 새로운 네트워크 발견
        if (!visited[i]) {
            dfs(i, computers, visited, n);  // DFS 수행
            answer++;  // 네트워크 개수 증가
        }
    }

    return answer;  // 총 네트워크 개수 반환
}
