#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S, T;
	cin >> S >> T;
	S = " " + S;
	T = " " + T;
	vector<vector<int>> dp(S.size(), vector<int>(T.size()));
	vector<vector<int>> dp2(S.size(), vector<int>(T.size()));
	for (int i = 1; i < S.size(); ++i) {
		for (int j = 1; j < T.size(); ++j) {
			if (S[i] == T[j]) {
				dp[i][j] = dp[i - 1][j - 1] + 1;
			} else {
				if (dp[i - 1][j] >= dp[i][j - 1]) {
					dp[i][j] = dp[i - 1][j];
					dp2[i][j] = 1;
				} else {
					dp[i][j] = dp[i][j - 1];
					dp2[i][j] = 2;
				}
			}
		}
	}
	int i = S.size() - 1;
	int j = T.size() - 1;
	string ans;
	while (i && j) {
		if (dp2[i][j] == 1) {
			--i;
		} else if (dp2[i][j] == 2) {
			--j;
		} else {
			ans += S[i];
			--i, --j;
		}	
	}
	reverse(ans.begin(), ans.end());
	cout << ans << "\n";
	return 0;
}
