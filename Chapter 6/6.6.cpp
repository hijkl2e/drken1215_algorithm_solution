#include <bits/stdc++.h>

using namespace std;

const double PI = acos(-1);

int A, B, C;

bool solve(double t) {
	double ft = A * t + B * sin(C * t * PI);
	return ft < 100;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> A >> B >> C;
	double lo = 0, hi = 200;
	for (int i = 0; i < 100; ++i) {
		double mid = (lo + hi) / 2;
		if (solve(mid)) {
			lo = mid;
		} else {
			hi = mid;
		}
	}
	cout << fixed << setprecision(15) << hi << "\n";
	return 0;
}
