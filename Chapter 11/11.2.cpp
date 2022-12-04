#include <bits/stdc++.h>

using namespace std;

using ll = long long;

class UF {
public:
	UF(int N) : par(N), sz(N, 1) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		return par[x] == x ? x : (par[x] = root(par[x]));
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y) {
		x = root(x);
		y = root(y);
		if (x == y) {
			return false;
		}
		if (sz[x] < sz[y]) {
			swap(x, y);
		}
		par[y] = x;
		sz[x] += sz[y];
		return true;
	}
	ll size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll N{}, M{};
	cin >> N >> M;
	vector<int> A(M);
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> B[i];
	}
	vector<ll> C(M);
	ll cnt = N * (N - 1) / 2;
	UF uf(N + 1);
	for (int i = M - 1; i >= 0; --i) {
		C[i] = cnt;
		if (!uf.same(A[i], B[i])) {
			cnt -= uf.size(A[i]) * uf.size(B[i]);
			uf.unite(A[i], B[i]);
		}
	}
	for (int i = 0; i < M; ++i) {
		cout << C[i] << "\n";
	}
	return 0;
}
