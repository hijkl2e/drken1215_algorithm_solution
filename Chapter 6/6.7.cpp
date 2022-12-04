#include <bits/stdc++.h>

using namespace std;

using ll = long long;

template <typename T = ll>
class FT {
public:
	FT(int n) : ft(n + 1) { }
	T rsq(int j) {
		T res{};
		while (j) {
			res += ft[j];
			j -= LSOne(j);
		}
		return res;
	}
	void update(int i, T v) {
		while (i < ft.size()) {
			ft[i] += v;
			i += LSOne(i);
		}
	}
private:
	T LSOne(T x) {
		return x & -x;
	}
	vector<T> ft;
};

ll N;
vector<int> A;

bool solve(int x) {
	vector<int> psum(N + 1);
	for (int i = 1; i <= N; ++i) {
		psum[i] = psum[i - 1] + (A[i] < x ? 1 : -1);
	}
	FT ft(2 * N + 1);
	ll cnt{};
	for (int i = 0; i <= N; ++i) {
		int j = psum[i] + N + 1;
		cnt += ft.rsq(j - 1);
		ft.update(j, 1);
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
