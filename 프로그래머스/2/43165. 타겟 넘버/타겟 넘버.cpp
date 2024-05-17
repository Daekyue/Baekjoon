#include <string>
#include <vector>

using namespace std;
int answer = 0;
void dfs(vector<int> numbers, int target, int index, int currentSum) {
    if (index == numbers.size()) {
        if (currentSum == target) {
            answer++;
        }
        return;
    }
    // 현재 숫자를 더하거나 빼는 두 가지 선택을 합니다.
    dfs(numbers, target, index + 1, currentSum + numbers[index]);
    dfs(numbers, target, index + 1, currentSum - numbers[index]);
}

int solution(vector<int> numbers, int target) {
    dfs(numbers, target, 0, 0);
    return answer;
}