#include <iostream> 
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int num[100000];
	int result = 0;
	int N, M, temp;
	int x, y;
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> temp;
		num[i] = num[i - 1] + temp;
	}
	for (int i = 0; i < M; i++) {
		cin >> x >> y;
		cout << num[y] - num[x - 1] << "\n";
	}
}