#include <bits/stdc++.h>

using namespace std;

int binary_search(int lo, int hi, int key) {
	int cnt = 0;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (key < mid) {
			hi = mid;
		} else {
			lo = mid;
		}
		++cnt;
	}
	return cnt;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int max_cnt = 0;
	for (int i = 0; i < 100; ++i) {
		max_cnt = max(max_cnt, binary_search(0, 100, i));
	}
	cout << max_cnt << "\n";
	return 0;
}
