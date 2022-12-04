#include <bits/stdc++.h>

using namespace std;

using ll = long long;

vector<ll> memo;

ll tribo(int N) {
	if (N <= 2) {
		return N / 2;
	}
	if (memo[N] != -1) {
		return memo[N];
	}
	return memo[N] = tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	memo.assign(50, -1);
	for (int i = 2; i < 50; ++i) {
		cout << i << " 항째: " << tribo(i) << "\n";
	}
	return 0;
}
