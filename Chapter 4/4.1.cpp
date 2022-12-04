#include <bits/stdc++.h>

using namespace std;

using ll = long long;

ll tribo(int N) {
	if (N <= 2) {
		return N / 2;
	}
	return tribo(N - 1) + tribo(N - 2) + tribo(N - 3);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	for (int i = 0; i < 10; ++i) {
		cout << i << " 항째: " << tribo(i) << "\n";
	}
	return 0;
}
