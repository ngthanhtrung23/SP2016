#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;

const int W = 1e7, N = 4e4, INF = 1e9;
int tree[4*W], com[4*W], n, l[N], r[N];

void update(int k, int l, int r, int x, int y) {
	if(y < l || r < x || l > r) return;
	if(x <= l && r <= y) {
		++com[k]; ++tree[k];
	} else {
		update(2*k+1, l, (l+r)/2, x, y);
		update(2*k+2, (l+r)/2+1, r, x, y);
		tree[k] = min(tree[2*k+1], tree[2*k+2]) + com[k];
	}
}

int get(int k, int l, int r, int x, int y) {
	if(y < l || r < x || l > r) return INF;
	if(x <= l && r <= y) return tree[k];
	return min(get(2*k+1, l, (l+r)/2, x, y), get(2*k+2, (l+r)/2+1, r, x, y)) + com[k];
}

void enter() {
	scanf("%d", &n);
	for(int i = 0; i < n; ++i) {
		scanf("%d%d", &l[i], &r[i]);
		--l[i]; --r[i];
	}
}

void solve() {
	int L = *min_element(l, l+n);
	int R = *max_element(r, r+n);
	memset(tree, 0, 4 * (R-L+1) * sizeof(int));
	memset(com, 0, 4 * (R-L+1) * sizeof(int));
	int res = 0;
	for(int i = n-1; i >= 0; --i) {
		update(0, L, R, l[i], r[i]);
		if(get(0, L, R, l[i], r[i]) == 1) ++res;
	}
	printf("%d\n", res);
}

int main() {
	int t; scanf("%d", &t);
	for(int i = 0; i < t; ++i) {
		enter();
		solve();
	}
	return 0;
}

