#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main() {
    string A, B;
    cin >> A >> B;

    // A와 B의 길이 맞추기
    int maxLength = max(A.length(), B.length());
    A = string(maxLength - A.length(), '0') + A;
    B = string(maxLength - B.length(), '0') + B;

    // 각 자리별로 더하면서 올림수(Carry) 처리
    string result;
    int carry = 0;
    for (int i = maxLength - 1; i >= 0; --i) {
        int sum = (A[i] - '0') + (B[i] - '0') + carry;
        result.push_back((sum % 10) + '0'); // 현재 자리에 대한 결과 저장
        carry = sum / 10; // 다음 자리로의 올림수 계산
    }

    // 마지막 올림수 처리
    if (carry)
        result.push_back(carry + '0');

    // 결과 역순 출력
    reverse(result.begin(), result.end());
    cout << result << endl;

    return 0;
}