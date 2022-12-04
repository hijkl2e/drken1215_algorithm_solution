#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int INF = 1e9 + 7;
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int H{}, W{};
	cin >> H >> W;
	vector<string> c(H);
	for (int i = 0; i < H; ++i) {
		cin >> c[i];
	}
	ii s, g;
	for (int i = 0; i < H; ++i) {
		for (int j = 0; j < W; ++j) {
			if (c[i][j] == 's') {
				s = {i, j};
			} else if (c[i][j] == 'g') {
				g = {i, j};
			}
		}
	}
	vector<vector<int>> d(H, vector<int>(W, INF));
	deque<ii> dq;
	d[s.first][s.second] = 0;
	dq.push_back(s);
	while (!dq.empty()) {
		auto [x, y] = dq.front(); dq.pop_front();
		for (int i = 0; i < 4; ++i) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (0 <= nx && nx < H && 0 <= ny && ny < W && d[nx][ny] == INF) {
				d[nx][ny] = d[x][y];
				if (c[nx][ny] == '#') {
					++d[nx][ny];
					dq.push_back({nx, ny});
				} else {
					dq.push_front({nx, ny});
				}
			}
		}
	}
	cout << (d[g.first][g.second] <= 2 ? "YES" : "NO") << "\n";
	return 0;
}
