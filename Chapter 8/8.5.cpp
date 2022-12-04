#include <bits/stdc++.h>

using namespace std;

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
	unordered_set<int> S(A.begin(), A.end());
	int cnt = 0;
	for (int i = 0; i < M; ++i) {
		cnt += S.count(B[i]);
	}
	cout << cnt << "\n";
	return 0;
}
