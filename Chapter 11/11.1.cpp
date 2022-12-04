#include <bits/stdc++.h>

using namespace std;

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
	vector<int> A(M);
	vector<int> B(M);
	for (int i = 0; i < M; ++i) {
		cin >> A[i] >> B[i];
	}
	int ans{};
	for (int i = 0; i < M; ++i) {
		UF uf(N + 1);
		for (int j = 0; j < M; ++j) {
			if (i == j) {
				continue;
			}
			uf.unite(A[j], B[j]);
		}
		int cnt{};
		for (int j = 1; j <= N; ++j) {
			if (uf.root(j) == j) {
				++cnt;
			}
		}
		if (cnt > 1) {
			++ans;
		}
	}
	cout << ans << "\n";
	return 0;
}
