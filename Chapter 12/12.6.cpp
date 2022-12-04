#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int phi(int x) {
	int ret = 1;
	for (int i = 2; i * i <= x; ++i) {
		int y = 1;
		while (x % i == 0) {
			x /= i;
			y *= i;
		}
		ret *= y - y / i;
	}
	if (x > 1) {
		ret *= x - 1;
	}
	return ret;
}

ll pow(__int128 x, ll y, ll mod) {
	__int128 ret = 1;
	while (y) {
		if (y % 2) {
			ret = ret * x % mod;
		}
		x = x * x % mod;
		y /= 2;
	}
	return ret;
}

ll solve(ll A, ll M) {
	if (M == 1) {
		return 1;
	}
	ll P = phi(M);
	ll L = lcm(M, P);
	return pow(A, solve(A, P), L) + L;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int Q{};
	cin >> Q;
	while (Q--) {
		int A{}, M{};
		cin >> A >> M;
		ll ans = solve(A, M);
		cout << ans << "\n";
	}
	return 0;
}
