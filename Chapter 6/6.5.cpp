#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int N, K;
vector<ll> A, B;

bool solve(ll x) {
	int cnt = 0;
	for (int i = 0; i < N; ++i) {
		cnt += upper_bound(B.begin(), B.end(), x / A[i]) - B.begin();
	}
	return cnt < K;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> K;
	A.resize(N);
	B.resize(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	sort(B.begin(), B.end());
	ll lo = 1, hi = 4e18;
	while (lo + 1 < hi) {
		ll mid = (lo + hi) / 2;
		if (solve(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << hi << "\n";
	return 0;
}
