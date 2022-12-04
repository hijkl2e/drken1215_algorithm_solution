#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &A, int l, int r, int p_idx, int k) {
	int p_val = A[p_idx];
	swap(A[p_idx], A[r - 1]);
	int i = l;
	for (int j = l; j < r - 1; ++j) {
		if (A[j] < p_val) {
			swap(A[i++], A[j]);
		}
	}
	if (k < i) {
		swap(A[i], A[r - 1]);
		return i;
	}
	for (int j = i; j < r - 1; ++j) {
		if (A[j] == p_val) {
			swap(A[i++], A[j]);
		}
	}
	swap(A[i], A[r - 1]);
	return min(k, i);
}

int partition5(vector<int> &A, int l, int r) {
	sort(A.begin() + l, A.begin() + r);
	return (l + r) / 2;
}

int select(vector<int> &, int, int, int);

int pivot(vector<int> &A, int l, int r) {
	if (r - l <= 5) {
		return partition5(A, l, r);
	}
	for (int i = l; i < r; i += 5) {
		int median = partition5(A, i, min(i + 5, r));
		swap(A[median], A[l + (i - l) / 5]);
	}
	int size = (r - l - 1) / 5 + 1;
	int mid = l + size / 2 + 1;
	select(A, l, l + size, mid);
	return mid;
}

int select(vector<int> &A, int l, int r, int k) {
	if (l + 1 == r) {
		return A[l];
	}
	int p_idx = pivot(A, l, r);
	p_idx = partition(A, l, r, p_idx, k);
	if (k < p_idx) {
		return select(A, l, p_idx, k);
	} else if (k > p_idx) {
		return select(A, p_idx + 1, r, k);
	} else {
		return A[k];
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int N{};
	cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i];
	}
	for (int i = 0; i < N; ++i) {
		cout << select(A, 0, N, i) << (i == N - 1 ? "\n" : " ");
	}
	return 0;
}
