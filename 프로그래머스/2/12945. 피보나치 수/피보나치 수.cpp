#include <string>
#include <vector>
 
using namespace std;
int arr[100001];
int solution(int n) {
    int answer = 0;
    
    arr[0]=0;
    arr[1]=1;
    
    for(int i=2;i<=n;i++){
        arr[i] = (arr[i-2]+arr[i-1])%1234567; // 해당 수는 적당히 큰 수와 소수라는 조건을 충족하여 1234567로 나눈 나머지를 구한다
    }
    
    answer = arr[n];
    return answer;
}
