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
	stack<ll> st;
	string tok;
	while (cin >> tok) {
		if (isdigit(tok[0])) {
			st.push(stoll(tok));
		} else {
			ll y = st.top(); st.pop();
			ll x = st.top(); st.pop();
			st.push(op[tok](x, y));
		}
	}
	cout << st.top() << "\n";
	return 0;
}
