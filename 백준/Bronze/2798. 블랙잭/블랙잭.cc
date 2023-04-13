#include <iostream> 
using namespace std;

int main() {

    int A, B;
    cin >> A >> B;
    int num[100];
    int max = 0;
    for (int i = 0; i < A; i++) {
        cin >> num[i];
    }
    for (int i = 0; i < A - 2; i++) {
        for (int j = i + 1; j < A - 1; j++) {
            for (int k = j + 1; k < A; k++) {
                int sum = num[i] + num[j] + num[k];
                if (sum <= B && sum > max) {
                    max = sum;
                }
            }
        }
    }
    cout << max;
}
