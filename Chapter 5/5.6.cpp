#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, W{};
	cin >> N >> W;
	vector<int> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<int> M(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> M[i];
	}
	vector<vector<int>> dp(N + 1, vector<int>(W + 1, INF));
	dp[0][0] = 0;
	for (int i = 1; i <= N; ++i) {
		for (int j = 0; j <= W; ++j) {
			if (dp[i - 1][j] < INF) {
				dp[i][j] = 0;
			} else if (j >= A[i] && dp[i][j - A[i]] < M[i]) {
				dp[i][j] = dp[i][j - A[i]] + 1;
			}
		}
	}
	cout << (dp[N][W] < INF ? "Yes" : "No") << "\n";
	return 0;
}
