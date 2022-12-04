#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9 + 7;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{};
	cin >> K;
	vector<int> d(K, INF);
	deque<int> dq;
	d[1] = 1;
	dq.push_back(1);
	while (!dq.empty()) {
		int x = dq.front(); dq.pop_front();
		int y = 10 * x % K;
		if (d[y] > d[x]) {
			d[y] = d[x];
			dq.push_front(y);
		}
		y = (x + 1) % K;
		if (d[y] > d[x] + 1) {
			d[y] = d[x] + 1;
			dq.push_back(y);
		}
	}
	cout << d[0] << "\n";
	return 0;
}
