#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<int>> G(N + 1);
	while (M--) {
		int x{}, y{};
		cin >> x >> y;
		G[x].push_back(y);
	}
	vector<int> ind(N + 1);
	for (int i = 1; i <= N; ++i) {
		for (int x : G[i]) {
			++ind[x];
		}
	}
	queue<int> q;
	for (int i = 1; i <= N; ++i) {
		if (ind[i] == 0) {
			q.push(i);
		}
	}
	vector<int> dp(N + 1);
	while (!q.empty()) {
		int x = q.front(); q.pop();
		for (int y : G[x]) {
			dp[y] = max(dp[y], dp[x] + 1);
			if (--ind[y] == 0) {
				q.push(y);
			}
		}
	}
	int ans{};
	for (int i = 1; i <= N; ++i) {
		ans = max(ans, dp[i]);
	}
	cout << ans << "\n";
	return 0;
}
