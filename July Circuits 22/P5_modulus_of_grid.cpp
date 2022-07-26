#include <iostream>
#define MX 100000
using namespace std;

int gcd(int a, int b) {
	int g;
	while (b) {
		g = b;
		b = a % b;
		a = g;
	}
	return g;
}

int main(){
	int n, m;
	cin >> n >> m;
	int *na, *ma, *ng, *mg;
	na = new int[n]();
	ng = new int[n]();
	ma = new int[m]();
	mg = new int[m]();
	for (int i = 1; i < n; i ++) {
		ng[gcd(i, n)] ++;
	}
	for (int i = 1; i < n; i ++) if(ng[i]) {
		for (int j = 0; j < n; j += i)
			na[j] += ng[i];
	}
	for (int i = 1; i < m; i ++) {
		mg[gcd(i, m)] ++;
	}
	for (int i = 1; i < m; i ++) if(mg[i]) {
		for (int j = 0; j < m; j += i)
			ma[j] += mg[i];
	}
	int q;
	cin >> q;
	while (q --) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		int x, y;
		x = (x2 - x1 + n) % n;
		y = (y2 - y1 + m) % m;
		cout << (__int64_t)na[x] * ma[y] << endl;
	}

	delete[] na;
	delete[] ng;
	delete[] ma;
	delete[] mg;
	return 0;
}
