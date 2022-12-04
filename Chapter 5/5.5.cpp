#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, W{};
	cin >> N >> W;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	deque<bool> dp(W + 1);
	dp[0] = true;
	for (int i = 1; i <= W; ++i) {
		for (int j = 0; j < N; ++j) {
			if (i >= A[j] && dp[i - A[j]]) {
				dp[i] = true;
				break;
			}
		}
	}
	cout << (dp[W] ? "Yes" : "No") << "\n";
	return 0;
}
