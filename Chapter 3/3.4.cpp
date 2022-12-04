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
	int min = -1, max = -1;
	for (int i = 0; i < N; ++i) {
		if (min == -1 || A[i] < A[min]) {
			min = i;
		}
		if (max == -1 || A[i] > A[max]) {
			max = i;
		}
	}
	cout << (A[max] - A[min]) << "\n";
	return 0;
}
