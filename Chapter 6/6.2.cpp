#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	vector<int> B(N);
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i];
	}
	for (int i = 0; i < N; ++i) {
		cin >> C[i];
	}
	sort(A.begin(), A.end());
	sort(C.begin(), C.end());
	ll ans{};
	for (int i = 0; i < N; ++i) {
		ll Aj = lower_bound(A.begin(), A.end(), B[i]) - A.begin();
		ll Cj = N - (upper_bound(C.begin(), C.end(), B[i]) - C.begin());
		ans += Aj * Cj;
	}
	cout << ans << "\n";
	return 0;
}
