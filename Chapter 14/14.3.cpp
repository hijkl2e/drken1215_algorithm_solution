#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(3 * N);
	while (M--) {
		int u{}, v{};
		cin >> u >> v;
		u = 3 * (u - 1);
		v = 3 * (v - 1);
		for (int i = 0; i < 3; ++i) {
			G[u + i].push_back(v + (i + 1) % 3);
		}
	}
	int S{}, T{};
	cin >> S >> T;
	S = 3 * (S - 1);
	T = 3 * (T - 1);
	vector<int> d(3 * N, INF);
	queue<int> q;
	d[S] = 0;
	q.push(S);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (d[y] == INF) {
				d[y] = d[x] + 1;
				q.push(y);
			}
		}
	}
	cout << (d[T] == INF ? -1 : (d[T] / 3)) << "\n";
	return 0;
}
