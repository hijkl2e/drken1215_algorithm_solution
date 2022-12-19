#include <bits/stdc++.h>

using namespace std;

using iii = tuple<int, int, int>;

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
	int N{}, M{};
	while (cin >> N >> M, N) {
		vector<iii> E(M);
		for (int i = 0; i < M; ++i) {
			int s{}, t{}, c{};
			cin >> s >> t >> c;
			E[i] = {c, s, t};
		}
		sort(E.begin(), E.end());
		UF uf(N + 1);
		int cnt{};
		for (auto &[w, u, v] : E) {
			if (uf.unite(u, v) && ++cnt == N / 2) {
				cout << w << "\n";
				break;
			}
		}
	}
	return 0;
}
