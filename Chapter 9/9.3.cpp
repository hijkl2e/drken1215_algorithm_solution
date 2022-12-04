#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	string S;
	cin >> S;
	vector<ii> A;
	A.reserve(S.size() / 2);
	stack<int> St;
	for (int i = S.size() - 1; i >= 0; --i) {
		if (S[i] == ')') {
			St.push(i);
		} else {
			if (St.empty()) {
				break;
			}
			int x = St.top(); St.pop();
			A.push_back({i, x});
		}
	}
	if (A.size() == S.size() / 2) {
		cout << "Yes\n";
		reverse(A.begin(), A.end());
		for (int i = 0; i < A.size(); ++i) {
			cout << "(" << A[i].first << ", " << A[i].second << ")\n";
		}
	} else {
		cout << "No\n";
	}
	return 0;
}
