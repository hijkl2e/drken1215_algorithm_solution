#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<vector<int>> A(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			cin >> A[i][j];
		}
	}
	vector<vector<int>> dp(N + 1, vector<int>(3));
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j < 3; ++j) {
			dp[i][j] = max(dp[i - 1][(j + 1) % 3], dp[i - 1][(j + 2) % 3]) + A[i][j];
		}
	}
	int ans{};
	for (int i = 0; i < 3; ++i) {
		ans = max(ans, dp[N][i]);
	}
	cout << ans << "\n";
	return 0;
}
