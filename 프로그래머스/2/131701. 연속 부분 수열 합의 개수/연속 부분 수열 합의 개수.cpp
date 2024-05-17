#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

int solution(vector<int> elements) {
    unordered_set<int> unique_sums;
    int n = elements.size();

    // 원형 수열을 처리하기 위해 elements를 두 배로 확장
    vector<int> extended_elements(elements.begin(), elements.end()); // elements 벡터의 복사본 생성
    extended_elements.insert(extended_elements.end(), elements.begin(), elements.end()); // elements의 원소를 extended_elements의 끝에 추가

    // 모든 가능한 길이의 연속 부분 수열의 합을 계산
    for (int length = 1; length <= n; ++length) {
        for (int start = 0; start < n; ++start) {
            int sum = 0;
            for (int i = start; i < start + length; ++i) {
                sum += extended_elements[i];
            }
            unique_sums.insert(sum);
        }
    }

    return unique_sums.size();
}
