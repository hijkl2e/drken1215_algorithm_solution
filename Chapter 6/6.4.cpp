#include <bits/stdc++.h>

using namespace std;

int N, C;
vector<int> x;

bool solve(int d) {
	int cnt = C - 1;
	int i = 0;
	for (int j = 1; j < x.size(); ++j) {
		if (x[j] - x[i] >= d) {
			i = j;
			if (--cnt == 0) {
				return true;
			}
		}
	}
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int TC{};
	cin >> TC;
	while (TC--) {
		cin >> N >> C;
		x.resize(N);
		for (int i = 0; i < N; ++i) {
			cin >> x[i];
		}
		sort(x.begin(), x.end());
		int lo = 0, hi = 1e9 + 7;
		while (lo + 1 < hi) {
			int mid = (lo + hi) / 2;
			if (solve(mid)) {
				lo = mid;
			} else {
				hi = mid;
			}
		}
		cout << lo << "\n";
	}
	return 0;
}
