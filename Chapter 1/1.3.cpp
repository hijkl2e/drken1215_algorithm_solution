#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<int> a{-1, 2};
vector<int> b{-1, -1};
vector<vector<int>> c{{-1, 3, -1}, {-1, -1}};
vector<int> d{-1, 4, -1};

ll vec_to_num(const vector<int> &v) {
	ll val = 0;
	for (int i = v.size() - 1; i >= 0; --i) {
		val = 10 * val + v[i];
	}
	return val;
}

vector<int> num_to_vec(ll num) {
	vector<int> v;
	while (num) {
		v.push_back(num % 10);
		num /= 10;
	}
	return v;
}

bool satisfy(vector<int> &v1, ll num) {
	vector<int> v2 = num_to_vec(num);
	if (v1.size() != v2.size()) {
		return false;
	}
	for (int i = 0; i < v1.size(); ++i) {
		if (v1[i] != -1 && v1[i] != v2[i]) {
			return false;
		}
	}
	return true;
}

void solve(int s) {
	int i = s;
	if (i < a.size()) {
		if (a[i] == -1) {
			for (a[i] = (i == a.size() - 1); a[i] < 10; ++a[i]) {
				solve(s + 1);
			}
			a[i] = -1;
		} else {
			solve(s + 1);
		}
		return;
	}
	i -= a.size();
	ll A = vec_to_num(a);
	if (i < b.size()) {
		if (b[i] == -1) {
			for (b[i] = (i == b.size() - 1); b[i] < 10; ++b[i]) {
				if (satisfy(c[i], A * b[i])) {
					solve(s + 1);
				}
			}
			b[i] = -1;
		} else {
			if (satisfy(c[i], A * b[i])) {
				solve(s + 1);
			}
		}
		return;
	}
	ll B = vec_to_num(b);
	ll C = A * B;
	if (satisfy(d, C)) {
		cout << A << "\n" << B << "\n";
		while (B) {
			cout << A * (B % 10) << "\n";
			B /= 10;
		}
		cout << C << "\n";
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	solve(0);
	return 0;
}
