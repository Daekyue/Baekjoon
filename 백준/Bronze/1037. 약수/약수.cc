#include <iostream>
using namespace std;


int main() {
    int N,B;
    int num[50];
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N - 1; i++) {
			while (num[i] > num[i + 1]) {
				B = num[i];
				num[i] = num[i + 1];
				num[i + 1] = B;
			}
		}
	}
	cout << num[0] * num[N - 1];
	return 0;
}