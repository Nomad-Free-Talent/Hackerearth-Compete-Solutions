#include <iostream>
#define MX	400000
using namespace std;

struct Node {
	int sz;
	int cnt;
};
class SizeList {
	Node list[MX * 2];
	int parent[MX * 2];
	int child[MX * 2];
	int size_pos[MX + 1];
	int head, tail;
	int stack_cnt;
public:
	void init(int n) {
		for (int i = 0; i <= n; i ++) size_pos[i] = -1;
		list[0].sz = 1;
		list[0].cnt = n;
		head = tail = 0;
		parent[0] = child[0] = -1;
		size_pos[1] = 0;
		stack_cnt = 1;
	}
	void remove(int sz) {
		if (size_pos[sz] == -1) {
			cout << "error" << endl;
		} else {
			int pos = size_pos[sz];
			list[pos].cnt --;
			if (list[pos].cnt == 0) {
				if (head == pos) {
					head = child[pos];
				} else {
					child[parent[pos]] = child[pos];
				}
				if (tail == pos) {
					tail = parent[pos];
				} else {
					parent[child[pos]] = parent[pos];
				}
				size_pos[sz] = -1;
			}
		}
	}
	void insert(int sz) {
		if (size_pos[sz] == -1) {
			int p;
			for (p = tail; p != -1; p = parent[p]) if (list[p].sz < sz) {
				list[stack_cnt].sz = sz;
				list[stack_cnt].cnt = 1;
				size_pos[sz] = stack_cnt;
				parent[stack_cnt] = p;
				if (p == tail) {
					tail = stack_cnt;
					child[stack_cnt] = -1;
					child[p] = stack_cnt;
				} else {
					parent[child[p]] = stack_cnt;
					child[stack_cnt] = child[p];
					child[p] = stack_cnt;
				}
				stack_cnt ++;
				break;
			}
		} else {
			list[size_pos[sz]].cnt ++;
		}
	}
	int calc(int cnt) {
		int res = 0;
		for (int p = tail; p != -1 && cnt != 0; p = parent[p]) {
			if (cnt > list[p].cnt) {
				res = res + list[p].cnt * list[p].sz;
				cnt -= list[p].cnt;
			} else {
				res = res + cnt * list[p].sz;
				cnt = 0;
			}
		}
		return res;
	}
	void print() {
		int mx = 0;
		for (int p = head; p != -1; p = child[p]) {
			cout << "size: " << list[p].sz << " cnt: " << list[p].cnt << endl;
			mx = mx > list[p].sz ? mx : list[p].sz;
		}
		for (int i = 1; i <= mx; i ++) cout << size_pos[i] << ' ';
		cout << endl;
	}
};

SizeList list;
int parent[MX + 1];
int size[MX + 1];
int deep[MX + 1];
int dirt = 0;

void getInt(int &num) {
	register char ch;
	do {
		ch = getchar();
	} while (ch < '0' || ch > '9');
	num = 0;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) {
		num = num * 10 + ch - '0';
	}
}

void init(int n) {
	list.init(n);
	for (int i = 1; i <= n; i ++) {
		parent[i] = -1;
		size[i] = 1;
		deep[i] = 1;
	}
}

int getParent(int n) {
	if (parent[n] == -1) return n;
	return getParent(parent[n]);
}

void join(int a, int b) {
	int pa, pb;
	pa = getParent(a);
	pb = getParent(b);
	if (pa != pb) {
		int new_size = size[pa] + size[pb];
		list.insert(new_size);
		list.remove(size[pa]);
		list.remove(size[pb]);

		if (deep[pa] > deep[pb]) {
			parent[pb] = pa;
			size[pa] = new_size;
		}
		else if(deep[pa] < deep[pb]) {
			parent[pa] = pb;
			size[pb] = new_size;
		}
		else {
			parent[pa] = pb;
			size[pb] = new_size;
			deep[pb] ++;
		}
	}
}

int main() {
	int n, q;
	int t, a, b;

	getInt(n); getInt(q);
	init(n);
	
	while (q --) {
		getInt(t);
		if (t == 1) {
			getInt(a);	getInt(b);
			join(a, b);
			// list.print();
			dirt = 1;
		} else {
			getInt(a);
			cout << list.calc(a + 1) + (!dirt && a == n ? 1 : 0) << endl;
		}
	}
}
