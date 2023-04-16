#include <iostream> 
#include <algorithm>
using namespace std;

int N[500000];
int M[500000];

void binarysearch(int n, int k)
{
	int low = 0;
	int high = n - 1;

	while (low <= high) {
		int mid = (low + high) / 2;
		if (N[mid] == k) {
			cout << "1" << "\n";
			return;
		}
		else {
			if (N[mid] > k) {
				high = mid - 1;
			}
			else {
				low = mid + 1;
			}
		}
	}
	cout << "0" << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	int A, B;
	cin >> A;
	
	for (int i = 0; i < A; i++) {
		cin >> N[i];
	}
	sort(N, N + A);	// #include 알고리즘을 통해 사용가능 첫번째인자 = 배열 포인터, 두번째 인자 = 배열 포인터 + 배열의 크기

	cin >> B;
	for (int i = 0; i < B; i++) {
		cin >> M[i];
	}
	for (int i = 0; i < B; i++) {
		binarysearch(A, M[i]);
	}
}