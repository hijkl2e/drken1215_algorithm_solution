#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll solve(ll N, ll val, bool use7, bool use5, bool use3) {
	if (N < val) {
		return 0;
	}
	int cnt = use7 && use5 && use3;
	cnt += solve(N, 10 * val + 7, true, use5, use3);
	cnt += solve(N, 10 * val + 5, use7, true, use3);
	cnt += solve(N, 10 * val + 3, use7, use5, true);
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	cout << solve(N, 0, false, false, false) << "\n";
	return 0;
}
