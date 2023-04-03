#include <iostream> 
using namespace std;

int main() {
	int	A, B, C;
	cin >> A >> B >> C;
	int answer1 = (A + B) % C;
	int answer2 = ((A % C) + (B % C)) % C;
	int answer3 = (A*B) % C;
	int answer4 = ((A % C) * (B % C)) % C;
	cout << answer1 << endl;
	cout << answer2 << endl;
	cout << answer3 << endl;
	cout << answer4 << endl;
}
