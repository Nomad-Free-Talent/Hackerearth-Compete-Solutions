#include <iostream>
#define MODULO 1000000007
#define ll long long
using namespace std;

ll times(const ll &a, const ll &b) {
	return (a * b) % MODULO;
}

ll pow(const ll &n, ll c) {
	ll p = n, res = 1;
	while (c) {
		res = c % 2 ? times(res, p) : res;
		p = times(p, p);
		c /= 2;
	}
	return res;
}

ll sum(const ll &a, const ll &b) {
	return (a + b) % MODULO;
}

ll C(const ll &n, const ll &k) {
	ll res = 1;
	for (ll i = 1, j = n; i <= k; i ++, j --) {
		res = times(res, j);
		res = times(res, pow(i, MODULO - 2));
	}
	return res;
}

ll func(char *str, int n, int k) {
	int validIdx = -1;
	int *diff = new int[n];
	cin >> str;
	for (int i = 0; i < n; i ++) {
		diff[i] = str[i] - 'a';
		if (validIdx == -1 && diff[i]) {
			validIdx = i;
		}
	}
	if (validIdx == -1) {
		delete[] diff;
		return 0;
	}
	ll res = 0;
	for (int i = validIdx, j = n - validIdx - 1; i <= n - k; i ++, j --) if (diff[i]) {
		ll subC;
		subC = times(pow(25, k - 1), C(j, k - 1));
		res = sum(res, times(diff[i], subC));
	}
	delete[] diff;
	return res;
}

int main(){
	int t;
	cin >> t;
	while (t --) {
		ll n, k;
		cin >> n >> k;
		char *str = new char[n + 1];
		cout << func(str, n, k) << endl;
		delete[] str;
	}
}
