#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;
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
	cin >> N >> M;
	vector<iii> E(M);
	for (int i = 0; i < M; ++i) {
		int s{}, d{}, c{};
		cin >> s >> d >> c;
		E[i] = {c, s, d};
	}
	sort(E.begin(), E.end());
	UF uf(N + 1);
	vector<int> F;
	F.reserve(N - 1);
	int C{};
	for (int i = 0; i < M; ++i) {
		auto &[w, u, v] = E[i];
		if (uf.unite(u, v)) {
			F.push_back(i);
			C += w;
		}
	}
	ii ans;
	for (int x : F) {
		int c{};
		uf = UF(N + 1);
		for (int i = 0; i < M; ++i) {
			if (i == x) {
				continue;
			}
			auto &[w, u, v] = E[i];
			if (uf.unite(u, v)) {
				c += w;
			}
		}
		if (c != C) {
			auto &[w, u, v] = E[x];
			++ans.first;
			ans.second += w;
		}
	}
	cout << ans.first << " " << ans.second << "\n";
	return 0;
}
