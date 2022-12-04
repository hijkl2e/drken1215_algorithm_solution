#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ii = pair<int, int>;

const ll INF = 4e18;

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
	void rbfs(int s, int t) {
		fill(d.begin(), d.end(), -1);
		queue<int> q;
		d[s] = 0;
		q.push(s);
		while (!q.empty()) {
			int u = q.front(); q.pop();
			for (int idx : G[u]) {
				auto &[v, cap, flow] = E[idx];
				if (d[v] == -1 && flow == cap) {
					d[v] = d[u] + 1;
					q.push(v);
				}
			}
		}
	}
	vector<edge> E;
	vector<vector<int>> G;
	vector<int> d;
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
	vector<int> last;
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	while (true) {
		int N{}, M{}, S{}, T{};
		cin >> N >> M >> S >> T;
		if (N == 0) {
			break;
		}
		MF mf(N + 1);
		while (M--) {
			int a{}, b{};
			cin >> a >> b;
			mf.add_edge(a, b, 1);
		}
		ii ans;
		ans.first = mf.dinic(S, T);
		vector<int> sd = mf.d;
		mf.rbfs(T, S);
		vector<int> td = mf.d;
		for (int i = 1; i <= N; ++i) {
			if (td[i] == -1) {
				continue;
			}
			for (int idx : mf.G[i]) {
				auto &[v, cap, flow] = mf.E[idx];
				if (sd[v] != -1 && cap) {
					++ans.second;
				}
			}
		}
		if (ans.second) {
			++ans.first;
		}
		cout << ans.first << " " << ans.second << "\n";
	}
	return 0;
}
