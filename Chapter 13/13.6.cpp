#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<vector<int>> G;
vector<int> vst;
deque<int> cycle;

bool dfs(int x) {
	vst[x] = 0;
	cycle.push_back(x);
	for (int y : G[x]) {
		if (vst[y] == -1) {
			if (dfs(y)) {
				return true;
			}
		} else if (vst[y] == 0) {
			cycle.push_back(y);
			while (cycle.front() != cycle.back()) {
				cycle.pop_front();
			}
			return true;
		}
	}
	cycle.pop_back();
	vst[x] = 1;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	G.resize(N);
	vst.assign(N, -1);
	while (M--) {
		int a{}, b{};
		cin >> a >> b;
		G[a].push_back(b);
	}
	for (int i = 0; i < N; ++i) {
		if (vst[i] == -1 && dfs(i)) {
			break;
		}
	}
	if (cycle.empty()) {
		cout << "No\n";
	} else {
		cout << "Yes\n";
		for (int i = 0; i < cycle.size(); ++i) {
			cout << cycle[i] << (i == cycle.size() - 1 ? "\n" : " ");
		}
	}
	return 0;
}
