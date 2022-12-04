#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> vst;

void bfs(int s) {
	queue<int> q;
	vst[s] = true;
	q.push(s);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			if (!vst[y]) {
				vst[y] = true;
				q.push(y);
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	G.resize(N);
	vst.resize(N);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
	}
	int s{}, t{};
	cin >> s >> t;
	bfs(s);
	cout << (vst[t] ? "Yes" : "No") << "\n";
	return 0;
}
