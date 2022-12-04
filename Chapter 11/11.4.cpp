#include <bits/stdc++.h>

using namespace std;

class UF {
public:
	UF(int N) : par(N), sz(N, 1), d(N) {
		for (int i = 0; i < N; ++i) {
			par[i] = i;
		}
	}
	int root(int x) {
		if (par[x] == x) {
			return x;
		} else {
			int y = par[x];
			par[x] = root(par[x]);
			d[x] += d[y];
			return par[x];
		}
	}
	bool same(int x, int y) {
		return root(x) == root(y);
	}
	bool unite(int x, int y, int z) {
		if (same(x, y)) {
			return false;
		}
		z += d[x] - d[y];
		x = root(x);
		y = root(y);
		if (sz[x] < sz[y]) {
			swap(x, y);
			z = -z;
		}
		par[y] = x;
		sz[x] += sz[y];
		d[y] = z;
		return true;
	}
	int size(int x) {
		return sz[root(x)];
	}
	int dist(int x) {
		return d[x];
	}
private:
	vector<int> par, sz, d;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	UF uf(N + 1);
	bool yes = true;
	while (M--) {
		int L{}, R{}, D{};
		cin >> L >> R >> D;
		if (!uf.unite(L, R, D) && uf.dist(R) - uf.dist(L) != D) {
			yes = false;
			break;
		}
	}
	cout << (yes ? "Yes" : "No") << "\n";
	return 0;
}
