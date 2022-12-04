#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N;
vector<ll> H, S;

bool solve(ll x) {
	vector<ll> t(N);
	for (int i = 0; i < N; ++i) {
		if (x < H[i]) {
			return false;
		}
		t[i] = (x - H[i]) / S[i];
	}
	sort(t.begin(), t.end());
	for (int i = 0; i < N; ++i) {
		if (t[i] < i) {
			return false;
		}
	}
	return true;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	H.resize(N);
	S.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> H[i] >> S[i];
	}
	ll lo = 1, hi = 2e14;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (solve(mid)) {
			hi = mid;
		} else {
			lo = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
