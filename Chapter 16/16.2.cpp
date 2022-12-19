#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;
using iiii = tuple<int, int, int, int>;

const int INF = 1e9 + 7;

class MF {
public:
	using edge = tuple<int, ll, ll>;
	MF(int V) : G(V), d(V), last(V) { }
	void add_edge(int u, int v, ll c, bool d = true) {
		G[u].push_back(E.size());
		E.push_back({v, c, 0});
		G[v].push_back(E.size());
		E.push_back({u, d ? 0 : c, 0});
	}
	ll dinic(int s, int t) {
		ll mf{};
		while (bfs(s, t)) {
			fill(last.begin(), last.end(), 0);
			while (ll f = dfs(s, t)) {
				mf += f;
			}
		}
		return mf;
	}
private:
	bool bfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while (q.size()) {
			int u = q.front(); q.pop();
			for (int idx : G[u]) {
				auto &[v, cap, flow] = E[idx];
				if (d[v] == -1 && flow < cap) {
					d[v] = d[u] + 1;
					q.push(v);
					if (v == t) {
						return true;
					}
				}
			}
		}
		return false;
	}
	ll dfs(int u, int t, ll f = INF) {
		if (u == t) {
			return f;
		}
		for (int &i = last[u]; i < G[u].size(); ++i) {
			auto &[v, cap, flow] = E[G[u][i]];
			if (d[v] != d[u] + 1 || flow == cap) {
				continue;
			}
			if (ll pushed = dfs(v, t, min(f, cap - flow))) {
				flow += pushed;
				auto &rflow = get<2>(E[G[u][i] ^ 1]);
				rflow -= pushed;
				return pushed;
			}
		}
		return 0;
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> d, last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, M{}, s{}, t{};
	cin >> N >> M >> s >> t;
	vector<iiii> E(M);
	for (int i = 0; i < M; ++i) {
		int u{}, v{}, d{}, c{};
		cin >> u >> v >> d >> c;
		E[i] = {u, v, d, c};
	}
	vector<vector<ii>> G(N + 1);
	for (auto &[u, v, d, c] : E) {
		G[u].push_back({v, d});
	}
	vector<int> dist(N + 1, INF);
	priority_queue<ii> pq;
	dist[s] = 0;
	pq.push({0, s});
	while (!pq.empty()) {
		auto [d, u] = pq.top(); pq.pop();
		if (dist[u] < d) {
			continue;
		}
		for (auto &[v, w] : G[u]) {
			int new_d = d + w;
			if (dist[v] > new_d) {
				dist[v] = new_d;
				pq.push({new_d, v});
			}
		}
	}
	MF mf(N + 1);
	for (auto &[u, v, d, c] : E) {
		if (dist[v] == dist[u] + d) {
			mf.add_edge(u, v, c);
		}
	}
	cout << mf.dinic(s, t) << "\n";
	return 0;
}
