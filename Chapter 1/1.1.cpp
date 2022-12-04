#include <bits/stdc++.h>

using namespace std;

void binary_search(int lo, int hi, int key) {
	while (lo + 1 < hi) {
		int mid = (lo + hi) / 2;
		cout << "당신: " << mid << "살 미만입니까?\n";
		cout << "A 씨: ";
		if (key < mid) {
			cout << "네.\n";
			hi = mid;
		} else {
			cout << "아니오.\n";
			lo = mid;
		}
	}
	cout << "당신: " << lo << "살입니다.\n";
	cout << "A 씨: 정답입니다.\n";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int age{};
	cin >> age;
	cout << "A 씨 나이를 맞히는 절차(" << age << "살인 경우)\n";
	binary_search(20, 36, age);
	return 0;
}
