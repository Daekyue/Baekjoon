#include <iostream>
using namespace std;


int main() {
    int T;
    cin >> T;
    int result = 0;
    for (int i = 0; i < T; i++) {
        result += i;
    }
    cout << result * 2;
}
