#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	ll ans = 0;
	for (int bit = 0; bit < (1 << (S.size() - 1)); ++bit) {
		ll res = 0, val = S[0] - '0';
		for (int i = 1; i < S.size(); ++i) {
			if (bit & (1 << (i - 1))) {
				res += val;
				val = S[i] - '0';
			} else {
				val = 10 * val + (S[i] - '0');
			}
		}
		res += val;
		ans += res;
	}
	cout << ans << "\n";
	return 0;
}
