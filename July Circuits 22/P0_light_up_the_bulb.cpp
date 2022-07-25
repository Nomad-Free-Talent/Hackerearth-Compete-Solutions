#include <iostream>
#define MAX_VAL	1e9
using namespace std;

struct Point {
	int x, y;
};

int calcDist (const Point &A, const Point &B) {
	return (A.x - B.x) * (A.x - B.x) + (A.y - B.y) * (A.y - B.y);
}

int minKey (int *key, bool *mstSet, int n) {
	int minKey = MAX_VAL, minIdx = 0;
	for (int i = 0; i < n; i ++) {
		if (mstSet[i] == false && minKey > key[i]) {
			minKey = key[i];
			minIdx = i;
		}
	}
	return minIdx;
}

int calcPrim (int** dist, int n) {
	bool* mstSet = new bool[n];
	int* key = new int[n];
	int edgeSum = 0, count;
	for (int i = 0; i < n; i ++) {
		key[i] = dist[0][i];
		mstSet[i] = false;
	}
	mstSet[0] = true;
	count = n - 1;
	while (count --) {
		int u = minKey(key, mstSet, n);
		mstSet[u] = true;
		edgeSum += key[u];
		for (int v = 0; v < n; v ++) {
			if (u != v && mstSet[v] == false && dist[u][v] < key[v]) {
				key[v] = dist[u][v];
			}
		}
	}
	delete[] mstSet;
	delete[] key;
	return edgeSum;
}

int main() {
	int n;
	cin >> n;
	Point *bulbs = new Point[n];
	int **dist = new int*[n];
	for (int i = 0; i < n; i ++) {
		cin >> bulbs[i].x >> bulbs[i].y;
		dist[i] = new int[n];
		for (int j = 0; j <= i; j ++) {
			dist[i][j] = dist[j][i] = calcDist(bulbs[i], bulbs[j]);
		}
	}
	cout << calcPrim(dist, n) << endl;
	for (int i = 0; i < n; i ++) delete[] dist[i];
	delete[] bulbs;
	delete[] dist;
}
