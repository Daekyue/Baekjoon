#include <iostream> 
using namespace std;

int main() {
	int	A;
	int count,num;
	
	while (cin >> A) {
		count = 1; num = 1;
		while (1) {
			if (num % A == 0) {
				break;
			}
			else {
				num = num * 10 + 1;
				num %= A;
				count++;
			}
			
		}
		cout << count << endl;
	}
	return 0;
}
