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
	stack<int> st;
	for (int i = S.size() - 1; i >= 0; --i) {
		if (S[i] == ')') {
			st.push(i);
		} else {
			if (st.empty()) {
				break;
			}
			int x = st.top(); st.pop();
			A.push_back({i, x});
		}
	}
	if (A.size() == S.size() / 2) {
		cout << "Yes\n";
		reverse(A.begin(), A.end());
		for (auto &p : A) {
			cout << "(" << p.first << ", " << p.second << ")\n";
		}
	} else {
		cout << "No\n";
	}
	return 0;
}
