#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int t;
	cin >> t;
	while (t --) {
		int n, a, b;
		cin >> n >> a >> b;
		if (n <= a) {
			cout << 1 << endl;
			continue;
		}
		if (a <= b) {
			cout << -1 << endl;
			continue;
		}
		cout << static_cast<int>(ceil(1.0 * (n - a) / (a - b)) * 2 + 1) << endl; 
	}
}
