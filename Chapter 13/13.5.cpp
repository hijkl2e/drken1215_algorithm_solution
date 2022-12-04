#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> G;

vector<int> toposort() {
	vector<int> ind(N);
	for (int i = 0; i < N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	queue<int> q;
	for (int i = 0; i < N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> ord;
	ord.reserve(N);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		ord.push_back(x);
		for (int y : G[x]) {
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	return ord;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	G.resize(N);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
	}
	auto ord = toposort();
	for (int i = 0; i < N; ++i) {
		cout << ord[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
