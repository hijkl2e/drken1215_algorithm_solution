#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, W{};
	cin >> N >> W;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<deque<bool>> dp(N + 1, deque<bool>(W + 1));
	dp[0][0] = true;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= W; ++j) {
			dp[i][j] = dp[i - 1][j];
			if (j >= A[i]) {
				dp[i][j] |= dp[i - 1][j - A[i]];
			}
		}
	}
	cout << (dp[N][W] ? "Yes" : "No") << "\n";
	return 0;
}
