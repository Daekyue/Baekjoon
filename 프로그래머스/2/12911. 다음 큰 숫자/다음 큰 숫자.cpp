#include <string>
#include <bitset>

using namespace std;

int solution(int n) {
    bitset<8> binary(n);            // n을 8비트로 변환하여 바이너리로 저장

    int count = binary.count();     // 1의 개수를 바로 얻을 수 있음

    while (true) {
        n++;                        // 다음 수로 증가
        binary = bitset<8>(n);      // 이진수로 변환

        if (binary.count() == count)
            break; 
    }
    
    return n;
}