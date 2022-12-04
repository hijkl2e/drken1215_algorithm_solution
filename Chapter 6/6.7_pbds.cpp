#include <bits/stdc++.h>
#include <bits/extc++.h>

using namespace std;
using namespace __gnu_pbds;

using ll = long long;
using ost = tree<pair<int, int>, null_type, less<pair<int, int>>,
			rb_tree_tag, tree_order_statistics_node_update>;

ll N;
vector<int> A;

bool solve(int x) {
	vector<int> psum(N + 1);
	for (int i = 1; i <= N; ++i) {
		psum[i] = psum[i - 1] + (A[i] < x ? 1 : -1);
	}
	ost tree;
	ll cnt{};
	for (int i = 0; i <= N; ++i) {
		cnt += tree.order_of_key({psum[i], -1});
		tree.insert({psum[i], i});
	}
	return cnt <= N * (N + 1) / 2 / 2;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N;
	A.resize(N + 1);
	for (int i = 1; i <= N; ++i) {
		cin >> A[i];
	}
	int lo = 1, hi = 1e9 + 7;
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		if (solve(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << lo << "\n";
	return 0;
}
