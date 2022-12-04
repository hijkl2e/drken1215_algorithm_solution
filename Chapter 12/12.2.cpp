#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ll cnt = min(M, A[i].second);
		ans += cnt * A[i].first;
		M -= cnt;
	}
	cout << ans << "\n";
	return 0;
}
