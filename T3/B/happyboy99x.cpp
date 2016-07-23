// Author: happyboy99x

#include<cstdio>

const int N = 501;
long long sum[N][N];
int a[N][N], m, n, k;

void enter() {
	scanf("%d%d%d", &m, &n, &k);
	for(int i = 1; i <= m; ++i)
		for(int j = 1; j <= n; ++j) {
			scanf("%d", &a[i][j]);
			sum[i][j] = sum[i][j-1] + a[i][j];
		}
}

void solve() {
	int s = m * n + 1, x0, y0, x1, y1;
	for(int l = 1; l <= n; ++l)
		for(int r = l; r <= n; ++r) {
			long long now = sum[1][r] - sum[1][l-1];
			for(int t = 1, b = 1; t <= n; ++t) {
				while(b <= n && now < k)
					++b, now += sum[b][r] - sum[b][l-1];
				if(now >= k && (r-l+1)*(b-t+1) < s) {
					s = (r-l+1)*(b-t+1);
					x0 = t; y0 = l; x1 = b; y1 = r;
				}
				now -= sum[t][r] - sum[t][l-1];
			}
		}
	if(s == m * n + 1) printf("-1\n");
	else printf("%d\n", s);
}

int main() {
	enter();
	solve();
	return 0;
}

