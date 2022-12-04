#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ll> A(N);
	vector<ll> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	ll sum{};
	for (int i = N - 1; i >= 0; --i) {
		ll r = (A[i] + sum) % B[i];
		sum += (B[i] - r) % B[i];
	}
	cout << sum << "\n";
	return 0;
}
