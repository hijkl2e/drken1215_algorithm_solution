#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ll> A(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	vector<ll> psum(N + 1);
	partial_sum(A.begin() + 1, A.end(), psum.begin() + 1);
	vector<vector<double>> dp(N + 1, vector<double>(M + 1));
	for (int i = 1; i <= N; ++i) {
		dp[i][1] = psum[i] / static_cast<double>(i);
		for (int j = 2; j <= min(M, i); ++j) {
			for (int k = j - 1; k < i; ++k) {
				dp[i][j] = max(dp[i][j], dp[k][j - 1]
						+ (psum[i] - psum[k]) / static_cast<double>(i - k));
			}
		}
	}
	cout << fixed << setprecision(6) << dp[N][M] << "\n";
	return 0;
}
