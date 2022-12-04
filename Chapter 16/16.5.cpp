#include <bits/stdc++.h>

using namespace std;

using ll = long long;

const ll INF = 4e18;
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

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
		while (!q.empty()) {
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
	int r{}, c{};
	cin >> r >> c;
	vector<string> C(r);
	for (int i = 0; i < r; ++i) {
		cin >> C[i];
	}
	MF mf(r * c + 2);
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (C[i][j] == '.') {
				if ((i + j) % 2) {
					mf.add_edge(i * c + j, r * c + 1, 1);
				} else {
					mf.add_edge(r * c, i * c + j, 1);
				}
			}
		}
	}
	for (int i = 0; i < r; ++i) {
		for (int j = i % 2; j < c; j += 2) {
			if (C[i][j] == '*') {
				continue;
			}
			for (int k = 0; k < 4; ++k) {
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (0 <= nx && nx < r && 0 <= ny && ny < c && C[nx][ny] == '.') {
					mf.add_edge(i * c + j, nx * c + ny, 1);
				}
			}
		}
	}
	int ans{};
	for (int i = 0; i < r; ++i) {
		for (int j = 0; j < c; ++j) {
			if (C[i][j] == '.') {
				++ans;
			}
		}
	}
	ans -= mf.dinic(r * c, r * c + 1);
	cout << ans << "\n";
	return 0;
}
