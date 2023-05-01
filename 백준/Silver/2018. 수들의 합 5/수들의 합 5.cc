#include <iostream> 
#include <algorithm>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int x,sum,start,end,count;
	cin >> x;
	sum = 1;
	start = 1;
	end = 1;
	count = 1;
	while (end != x) {
		sum = (start + end) * ((end - start + 1) / 2.0) ;
		if (sum == x) {
			count++;
			end++;
			sum = 1;
		}
		else if (sum > x) {
			sum = 1;
			start++;
		}
		else if (sum < x) {
			end++;
			sum = 1;
		}
	}
	cout << count;
}
