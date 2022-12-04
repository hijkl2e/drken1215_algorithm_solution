#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> H(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i];
	}
	vector<int> dp(N);
	for (int i = 1; i < N; ++i) {
		dp[i] = dp[i - 1] + abs(H[i] - H[i - 1]);
		if (i > 1) {
			dp[i] = min(dp[i], dp[i - 2] + abs(H[i] - H[i - 2]));
		}
	}
	cout << dp[N - 1] << "\n";
	return 0;
}
