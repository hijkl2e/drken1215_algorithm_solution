#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	vector<ii> B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	for (int i = 0; i < N; ++i) {
		cin >> B[i].first >> B[i].second;
	}
	sort(A.begin(), A.end());
	sort(B.begin(), B.end());
	set<int> S;
	int i{}, j{};
	int ans{};
	while (j < N) {
		if (i < N && A[i].first < B[j].first) {
			S.insert(A[i++].second);
		} else {
			auto it = S.lower_bound(B[j++].second);
			if (it != S.begin()) {
				S.erase(--it);
				++ans;
			}
		}
	}
	cout << ans << "\n";
	return 0;
}
