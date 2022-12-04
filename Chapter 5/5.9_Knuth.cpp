#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(A.begin() + 1, A.end(), psum.begin() + 1);
	vector<vector<ll>> dp(N + 1, vector<ll>(N + 2, INF));
	vector<vector<int>> opt(N + 1, vector<int>(N + 2));
	for (int i = 1; i <= N; ++i) {
		dp[i][i + 1] = 0;
		opt[i][i + 1] = i;
	}
	for (int s = 2; s <= N; ++s) {
		for (int i = 1; i + s <= N + 1; ++i) {
			int j = i + s;
			for (int k = opt[i][j - 1]; k <= opt[i + 1][j]; ++k) {
				ll val = dp[i][k] + dp[k][j];
				if (dp[i][j] > val) {
					dp[i][j] = val;
					opt[i][j] = k;
				}
			}
			dp[i][j] += psum[j - 1] - psum[i - 1];
		}
	}
	cout << dp[1][N + 1] << "\n";
	return 0;
}
