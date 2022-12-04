#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	map<string, function<ll(ll, ll)>> op{
		{"+", plus<ll>()},
		{"-", minus<ll>()},
		{"*", multiplies<ll>()},
		{"/", divides<ll>()}
	};
	stack<ll> S;
	string tok;
	while (cin >> tok) {
		if (isdigit(tok[0])) {
			S.push(stoll(tok));
		} else {
			ll y = S.top(); S.pop();
			ll x = S.top(); S.pop();
			S.push(op[tok](x, y));
		}
	}
	cout << S.top() << "\n";
	return 0;
}
