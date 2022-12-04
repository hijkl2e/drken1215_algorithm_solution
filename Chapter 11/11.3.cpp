#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

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
	int size(int x) {
		return sz[root(x)];
	}
private:
	vector<int> par, sz;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, K{}, L{};
	cin >> N >> K >> L;
	UF uf1(N + 1), uf2(N + 1);
	while (K--) {
		int p{}, q{};
		cin >> p >> q;
		uf1.unite(p, q);
	}
	while (L--) {
		int r{}, s{};
		cin >> r >> s;
		uf2.unite(r, s);
	}
	map<ii, int> F;
	for (int i = 1; i <= N; ++i) {
		++F[{uf1.root(i), uf2.root(i)}];
	}
	for (int i = 1; i <= N; ++i) {
		cout << F[{uf1.root(i), uf2.root(i)}] << (i == N ? "\n" : " ");
	}
	return 0;
}
