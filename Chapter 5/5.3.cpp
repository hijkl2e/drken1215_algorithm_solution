#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> P(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> P[i];
	}
	int W = accumulate(P.begin() + 1, P.end(), 0);
	vector<deque<bool>> dp(N + 1, deque<bool>(W + 1));
	dp[0][0] = true;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= W; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j >= P[i]) {
				dp[i][j] |= dp[i - 1][j - P[i]];
			}
		}
	}
	int ans = accumulate(dp[N].begin(), dp[N].end(), 0);
	cout << ans << "\n";
	return 0;
}
