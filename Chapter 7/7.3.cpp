#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<ii> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i].first >> A[i].second;
	}
	sort(A.begin(), A.end(), [](const ii &x, const ii &y) {
		return x.second < y.second;
	});
	bool yes = true;
	ll sum = 0;
	for (int i = 0; i < N; ++i) {
		sum += A[i].first;
		if (sum > A[i].second) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
