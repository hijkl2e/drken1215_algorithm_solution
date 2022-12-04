#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	vector<int> B(A.begin(), A.end());
	sort(B.begin(), B.end());
	vector<int> C(N);
	for (int i = 0; i < N; ++i) {
		C[i] = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
	}
	for (int i = 0; i < N; ++i) {
		cout << C[i] << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
