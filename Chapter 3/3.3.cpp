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
	int min1 = -1, min2 = -1;
	for (int i = 0; i < N; ++i) {
		if (min1 == -1 || A[i] < A[min1]) {
			min2 = min1;
			min1 = i;
		} else if (min2 == -1 || A[i] < A[min2]) {
			min2 = i;
		}
	}
	cout << A[min2] << "\n";
	return 0;
}
