#include <iostream> 
using namespace std;

int main() {	//65~90
	string N;
	int B;
	int sum = 0;
	int b =1;
	cin >> N >> B;
	for (int i = 0; i < N.length(); i++) {
		if (int(N[i]) > 64) {
			b = 1;
			int n = int(N[i]) - 55;
			for (int j = 0; j < N.length() - (i + 1); j++) {
				b = b * B;
			}
			sum = sum + n * b;
		}
		else {
			b = 1;
			int n = int(N[i]) - 48;
			for (int j = 0; j < N.length()-(i+1); j++) {
				b = b * B;
			}
			sum = sum + n * b;
		}
	}
	
	cout << sum;
}