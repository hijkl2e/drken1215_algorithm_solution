#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<int> P(N + 1);
		for (int i = 1; i <= N; ++i) {
			cin >> P[i];
		}
		vector<int> A;
		for (int i = 0; i < P.size(); ++i) {
			for (int j = i; j < P.size(); ++j) {
				if (P[i] + P[j] <= M) {
					A.push_back(P[i] + P[j]);
				}
			}
		}
		sort(A.begin(), A.end());
		int ans{};
		for (int x : A) {
			auto it = upper_bound(A.begin(), A.end(), M - x);
			ans = max(ans, x + *--it);
		}
		cout << ans << "\n";
	}
	return 0;
}
