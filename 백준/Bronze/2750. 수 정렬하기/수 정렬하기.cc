#include <iostream> 
using namespace std;

int main() {

	int A, B;
	cin >> A;
	int num[1000];

	for (int i = 0; i < A; i++) {
		cin >> num[i];
	}
	for (int j = 0; j < A; j++) {
		for (int i = 0; i < A - 1; i++) {
			while (num[i] > num[i + 1]) {
				B = num[i];
				num[i] = num[i + 1];
				num[i + 1] = B;
			}
		}
	}
	for (int i = 0; i < A; i++) {
		cout << num[i] << endl;
	}
}