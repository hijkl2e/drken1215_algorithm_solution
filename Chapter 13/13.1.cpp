#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> G;
deque<bool> vst;

void dfs(int x) {
	vst[x] = true;
	for (int y : G[x]) {
		if (!vst[y]) {
			dfs(y);
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
		G[b].push_back(a);
	}
	int ans{};
	for (int i = 0; i < N; ++i) {
		if (!vst[i]) {
			dfs(i);
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
