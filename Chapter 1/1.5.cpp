#include <bits/stdc++.h>

using namespace std;

using ii = pair<int, int>;

const int N = 8;
const int M = 8;
vector<vector<int>> G{
	{0, 1, 2, 3, 4, 5, 6, 7},
	{1, 2, 3, -1, 5, -1, 7, 8},
	{2, -1, 4, 5, 6, 7, 8, -1},
	{3, 4, 5, -1, -1, -1, 9, -1},
	{-1, 5, -1, -1, 12, 11, 10, -1},
	{7, 6, 7, -1, 13, -1, -1, 16},
	{8, -1, 8, -1, 12, 13, 14, 15},
	{9, -1, 9, 10, 11, 12, -1, 16}
};
vector<vector<int>> H(N, vector<int>(M, -1));
const int dx[4]{0, 1, 0, -1};
const int dy[4]{1, 0, -1, 0};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	vector<ii> path;
	ii now{N - 1, M - 1};
	path.push_back(now);
	while (G[now.first][now.second]) {
		for (int i = 0; i < 4; ++i) {
			int nx = now.first + dx[i];
			int ny = now.second + dy[i];
			if (0 <= nx && nx < N && 0 <= ny && ny < M
					&& G[nx][ny] == G[now.first][now.second] - 1) {
				now = {nx, ny};
				break;
			}
		}
		path.push_back(now);
	}
	reverse(path.begin(), path.end());
	for (auto &p : path) {
		H[p.first][p.second] = G[p.first][p.second];
	}
	for (int i = N - 1; i >= 0; --i) {
		for (int j = 0; j < M; ++j) {
			if (H[i][j] == -1) {
				cout << "   ";
			} else {
				cout << setw(3) << H[i][j];
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
