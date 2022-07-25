#include <bits/stdc++.h>
#include <iostream>
#define MX 200000
#define UP		0
#define DOWN	1
#define max(a, b) ((a)>(b)?(a):(b))
using namespace std;

struct node {
	int num;
	int length;
};
template <class T>
class Stack {
	T list[MX];
	int parent[MX];
	int child[MX];
	int cnt;
	int head;
	int tail;
	bool isUp;
public:
	Stack (bool up) {
		init(up);
	}
	void init (bool up) {
		isUp = up;
		cnt = 0;
		head = tail = -1;
	}
	void insert (T node, int &idx) {
		list[cnt] = node;
		parent[cnt] = idx;
		if (head == -1 && tail == -1) {
			child[cnt] = -1;
			tail = cnt;
			head = cnt;
		} else if (idx == -1) {
			parent[head] = cnt;
			child[cnt] = head;
			head = cnt;
		} else if (idx == tail) {
			child[idx] = cnt;
			child[cnt] = -1;
			tail = cnt;
		} else {
			parent[child[idx]] = cnt;
			child[cnt] = child[idx];
			child[idx] = cnt;
		}
		idx = cnt;
		cnt ++;
	}
	void update(T node, int idx) {
		list[idx] = node;
	}
	void clear(int length, int idx) {
		for (int op = child[idx]; op != -1; op = child[op]) {
			if (
				isUp && list[op].length <= length ||
				!isUp && list[op].length <= length
			) {
				if (parent[op] != -1) {
					child[parent[op]] = child[op];
				}
				if (child[op] != -1) {
					parent[child[op]] = parent[op];
				}
				if (op == tail) {
					tail = parent[op];
				}
			}
		}
	}
	int search(int num) {
		for (int op = tail; op != -1; op = parent[op]) {
			if (
				isUp && num >= list[op].num ||
				!isUp && num <= list[op].num
			) {
				return op;
			}
		}
		return -1;
	}
	T& operator[] (int idx) {
		return list[idx];
	}
};

int main() {
	int t;
	cin >> t;
	int dp[MX];
	Stack<node> upSt(true), downSt(false);
	while (t --) {
		int n;
		cin >> n;
		upSt.init(true);	downSt.init(false);
		std::memset(dp, 0, sizeof(int) * MX);
		int upRes, downRes;
		int res = 0;
		for (int i = 0; i < n; i ++) {
			int num, up, down;
			cin >> num;
			upRes = downRes = 0;
			up = upSt.search(num);
			down = downSt.search(num);
			
			if (up != -1) {
				upRes = max(upRes, upSt[up].length + 1);
			}
			if (down != -1) {
				downRes = max(downRes, downSt[down].length + 1);
			}
			upRes = max(upRes, dp[num] + 1);
			downRes = max(downRes, dp[num] + 1);

			node newNode;
			newNode.num = num;

			newNode.length = upRes;
			if (up == -1) {
				upSt.insert(newNode, up);
			}
			else if (newNode.length > upSt[up].length) {
				if (num == upSt[up].num) upSt.update(newNode, up);
				else upSt.insert(newNode, up);
			}
			upSt.clear(newNode.length, up);

			newNode.length = downRes;
			if (down == -1) {
				downSt.insert(newNode, down);
			}
			else if (newNode.length > downSt[down].length) {
				if (num == downSt[down].num) downSt.update(newNode, down);
				else downSt.insert(newNode, down);
			}
			downSt.clear(newNode.length, down);

			int subRes = max(upRes, downRes);
			dp[num] = max(dp[num], subRes);
			res = max(res, subRes);
		}
		cout << res << endl;
	}
	return 0;
}
