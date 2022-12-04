#include <bits/stdc++.h>

using namespace std;

vector<int> A;
vector<vector<int>> memo;

bool func(int n, int w) {
	if (n == 0) {
		return w == 0;
	}
	if (memo[n][w] != -1) {
		return memo[n][w];
	}
	return memo[n][w] = (func(n - 1, w) || func(n - 1, w - A[n - 1]));
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{}, W{};
	cin >> N >> W;
	A.resize(N);
	memo.assign(N + 1, vector<int>(W + 1, -1));
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	cout << (func(N, W) ? "Yes" : "No") << "\n";
	return 0;
}
