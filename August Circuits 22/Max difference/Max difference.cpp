#include <iostream>
using namespace std;
int main(){
	int t;
	cin >> t;
	while (t --) {
		int n;
		cin >> n;
		int *a = new int[n];
		int minA = 1e10, minB = 1e10;
		int maxA = 0, maxB = 0;
		for (int i = 0; i < n; i ++) {
			cin >> a[i];
			if (a[i] <= minA) {
				minB = minA;
				minA = a[i];
			} else if (a[i] <= minB) {
				minB = a[i];
			}
			if (a[i] >= maxA) {
				maxB = maxA;
				maxA = a[i];
			} else if (a[i] >= maxB) {
				maxB = a[i];
			}
		}
		if (n == 2) {
			cout << maxA - minA << endl;
		} else {
			cout << maxB + maxA - minB - minA << endl;
		}
		delete[] a;
	}
}