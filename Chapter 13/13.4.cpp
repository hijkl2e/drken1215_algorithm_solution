#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

int N, M;
vector<string> G;
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

vector<vector<int>> bfs(ii s) {
	vector<vector<int>> d(N, vector<int>(M, -1));
	queue<ii> q;
	d[s.first][s.second] = 0;
	q.push(s);
	while (!q.empty()) {
		auto [x, y] = q.front(); q.pop();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M
					&& G[nx][ny] != '#' && d[nx][ny] == -1) {
				d[nx][ny] = d[x][y] + 1;
				q.push({nx, ny});
			}
		}
	}
	return d;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> N >> M;
	G.resize(N);
	for (int i = N - 1; i >= 0; --i) {
		cin >> G[i];
	}
	ii s, g;
	for (int i = 0; i < N; ++i) {
		for (int j = 0; j < M; ++j) {
			if (G[i][j] == 'S') {
				s = {i, j};
			} else if (G[i][j] == 'G') {
				g = {i, j};
			}
		}
	}
	auto d = bfs(s);
	vector<ii> path;
	ii now = g;
	path.push_back(now);
	while (d[now.first][now.second]) {
		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M
					&& d[nx][ny] == d[now.first][now.second] - 1) {
				now = {nx, ny};
				break;
			}
		}
		path.push_back(now);
	}
	reverse(path.begin(), path.end());
	vector<vector<int>> D(N, vector<int>(M, -1));
	for (auto &p : path) {
		D[p.first][p.second] = d[p.first][p.second];
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < M; ++j) {
			if (D[i][j] == -1) {
				cout << "   ";
			} else {
				cout << setw(3) << D[i][j];
			}
		}
		cout << "\n";
	}
	for (int i = 0; i < path.size(); ++i) {
		cout << "(" << path[i].first << ", " << path[i].second << ")"
			  << (i == path.size() - 1 ? "\n" : " -> ");
	}
	return 0;
}
