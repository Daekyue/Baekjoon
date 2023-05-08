#include<iostream>
#include<algorithm>
#include<stack>
#include<stdlib.h>
#include<queue>

using namespace std;

struct cmp {
	bool operator()(int n1, int n2) {
		if (abs(n1) > abs(n2))
			return true;
		else if (abs(n1) == abs(n2))
			if (n1 > n2)
				return true;
			else
				return false;
		return false;
	}
};

int N, number,x;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	priority_queue<int, vector<int>, cmp> pq;
	cin >> N;
	while (N--) {
		cin >> number;
		if (number != 0) {
			pq.push(number);
		}
		else {
			if (!pq.empty()) {
				printf("%d\n", pq.top());
				pq.pop();
			}
			else {
				printf("0\n");
			}
		}
	}
}