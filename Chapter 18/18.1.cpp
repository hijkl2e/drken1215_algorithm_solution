#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> used;

bool dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		used[x] &= !dfs(y, x);
	}
	return used[x];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	used.assign(N + 1, true);
	for (int i = 0; i < N - 1; ++i) {
		int x{}, y{};
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, -1);
	int ans = accumulate(used.begin() + 1, used.end(), 0);
	cout << ans << "\n";
	return 0;
}
