#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{};
	cin >> N >> M;
	vector<vector<ii>> G(N + 1);
	while (M--) {
		int a{}, b{}, c{};
		cin >> a >> b >> c;
		G[a].push_back({b, -c});
	}
	vector<ll> d(N + 1, INF);
	d[1] = 0;
	bool inf = false;
	for (int i = 0; i < N; ++i) {
		for (int u = 1; u <= N; ++u) {
			if (d[u] == INF) {
				continue;
			}
			for (auto &[v, w] : G[u]) {
				ll new_d = d[u] + w;
				if (d[v] > new_d) {
					d[v] = new_d;
					inf |= v == N && i == N - 1;
				}
			}
		}
	}
	if (inf) {
		cout << "inf\n";
	} else {
		cout << -d[N] << "\n";
	}
	return 0;
}
