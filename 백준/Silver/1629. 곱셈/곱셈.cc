#include<bits/stdc++.h>

using namespace std;

long long answer(long long n, long long num, long long number)
{
    if (num == 1)
        return n % number;
    long long val = answer(n, num/2, number);
    val = val * val % number;
    if (num % 2 == 0) return val;
    return val * n % number;
}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    long long n, num, number;
    cin >> n >> num >> number;

    cout << answer(n, num, number);
}