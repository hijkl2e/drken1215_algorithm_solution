#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<vector<int>> G;
vector<vector<ll>> dp;
const int MOD = 1e9 + 7;

void dfs(int x, int p) {
	for (int y : G[x]) {
		if (y == p) {
			continue;
		}
		dfs(y, x);
		dp[0][x] *= dp[0][y] + dp[1][y];
		dp[0][x] %= MOD;
		dp[1][x] *= dp[0][y];
		dp[1][x] %= MOD;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	G.resize(N + 1);
	dp.assign(2, vector<ll>(N + 1, 1));
	for (int i = 0; i < N - 1; ++i) {
		int x{}, y{};
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, -1);
	int ans = (dp[0][1] + dp[1][1]) % MOD;
	cout << ans << "\n";
	return 0;
}
