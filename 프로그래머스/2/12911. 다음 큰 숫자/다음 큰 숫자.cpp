#include <bits/stdc++.h>
using namespace std;

int countOnes(int x) {
    int cnt = 0;
    while (x > 0) {
        cnt += (x % 2); // 0 또는 1
        x /= 2;
    }
    return cnt;
}

int solution(int n) {
    int target = countOnes(n);
    for (int m = n + 1; ; m++) {
        if (countOnes(m) == target) return m;
    }
}