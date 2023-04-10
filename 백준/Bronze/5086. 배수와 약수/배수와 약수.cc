#include <iostream> 
using namespace std;

int main() {

	int A, B;
	while (cin >> A >> B) {
		if (A == 0 && B == 0) {
			break;
		}
		if (A > B) {
			if (A % B == 0)
				cout << "multiple" <<endl;
			else {
				cout << "neither" << endl;
			}
		}
		else {
			if (B % A == 0) {
				cout << "factor" << endl;
			}
			else {
				cout << "neither" << endl;
			}
		}
	}
}