#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, K{};
	cin >> N >> M >> K;
	vector<int> A(N);
	vector<int> B(M);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < M; ++i) {
		cin >> B[i];
	}
	unordered_set<int> S(A.begin(), A.end());
	bool yes = false;
	for (int i = 0; i < M; ++i) {
		if (S.count(K - B[i])) {
			yes = true;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
