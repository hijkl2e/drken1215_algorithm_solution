#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
vector<int> color;

bool bfs(int s) {
	queue<int> q;
	color[s] = 0;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (color[y] == -1) {
				color[y] = 1 - color[x];
				q.push(y);
			} else {
				if (color[x] == color[y]) {
					return false;
				}
			}
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N);
	color.assign(N, -1);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	bool yes = true;
	for (int i = 0; i < N; ++i) {
		if (color[i] == -1 && !bfs(i)) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
