#include <iostream>
using namespace std;

// 거꾸로 생각해서 도착 지점에서 n을 깍아내려 간다고 생각
// n이 짝수일 경우 앞에서 n/2만큼 왔을 경우 점프를 사용하지 않고 바로 올 수 있으므로 ans를 더하지 않고 n값만 / 2
// n이 홀수일 경우 앞에서 점프 +1로 도달하는 것이 가장 짧으므로 ans++; n값은 내려가는 값이므로 -1

int solution(int n) 
{
    int ans = 0;
    
    while(n != 0)
    {
        if(n % 2 == 0)
            n /= 2;
        else
        {
            ans++;
            n -= 1;
        }
    }

    return ans;
}