#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	unordered_map<int, ll> F;
	for (int i = 0; i < N; ++i) {
		++F[A[i]];
	}
	ll cnt = 0;
	for (int i = 0; i < M; ++i) {
		auto it = F.find(B[i]);
		if (it != F.end()) {
			cnt += it->second;
		}
	}
	cout << cnt << "\n";
	return 0;
}
