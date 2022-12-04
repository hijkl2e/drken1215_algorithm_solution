#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{};
	cin >> N >> K;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	set<int> S;
	for (int i = 0; i < K; ++i) {
		S.insert(A[i]);
	}
	auto it = --S.end();
	cout << *it;
	for (int i = K; i < N; ++i) {
		S.insert(A[i]);
		if (*it > A[i]) {
			--it;
		}
		cout << " " << *it;
	}
	cout << "\n";
	return 0;
}
