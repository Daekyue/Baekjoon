#include<iostream>
#include<algorithm>
#include<stack>
#include<stdlib.h>
#include<queue>
#define MAX 5000

using namespace std;

int N, M, V;
int map[MAX][MAX];
bool visited[MAX];
queue<int> q;

void init() {
	for (int i = 1; i <= N; i++) {
		visited[i] = 0;
	}
}

void DFS(int v) {
	visited[v] = 1;
	cout << v << " ";

	for (int i = 1; i <= N; i++) {
		if (map[v][i] == 1 && visited[i] == 0) {
			DFS(i);
		}
	}
}

void BFS(int v) {
	q.push(v);
	visited[v] = 1;
	cout << v << " ";

	while (!q.empty()) {
		v = q.front();
		q.pop();

		for (int w = 1; w <= N; w++) {
			if (map[v][w] == 1 && visited[w] == 0) { 
				q.push(w);
				visited[w] = 1;
				cout << w << " ";
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N >> M >> V;

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		map[a][b] = 1;
		map[b][a] = 1;
	}
	DFS(V);
	init();
	cout << '\n';

	BFS(V);
	
}