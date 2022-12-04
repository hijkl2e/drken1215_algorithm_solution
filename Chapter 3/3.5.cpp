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
	int ans = 0;
	while (true) {
		bool flag = true;
		for (int i = 0; i < N; ++i) {
			if (A[i] % 2) {
				flag = false;
				break;
			} else {
				A[i] /= 2;
			}
		}
		if (flag) {
			++ans;
		} else {
			break;
		}
	}
	cout << ans << "\n";
	return 0;
}
