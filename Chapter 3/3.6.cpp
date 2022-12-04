#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int K{}, S{};
	cin >> K >> S;
	int ans = 0;
	for (int x = 0; x <= K; ++x) {
		for (int y = 0; y <= K; ++y) {
			int z = S - x - y;
			if (0 <= z && z <= K) {
				++ans;
			}	
		}
	}
	cout << ans << "\n";
	return 0;
}
