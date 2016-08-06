#include <bits/stdc++.h>
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << X << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define ll long long
#define SZ(x) ((int) (x).size())
using namespace std;

const ll MOD = 1e9 + 7;
const int MN = 100111;
ll gt[MN], inv_gt[MN];

ll power(ll x, ll k) {
	if (k == 0) return 1;
	if (k == 1) return x % MOD;
	ll mid = power(x, k >> 1);
	mid = mid * mid % MOD;

	if (k & 1) return mid * x % MOD;
	else return mid;
}

ll inverse(ll x) {
	return power(x, MOD - 2);
}

ll C(int n, int k) {
	assert(k >= 0 && k <= n);
	return gt[n] * inv_gt[k] % MOD * inv_gt[n - k] % MOD;
}

void init() {
	gt[0] = 1;
	FOR(i,1,MN - 1) gt[i] = gt[i-1] * i % MOD;

	REP(i,MN) inv_gt[i] = inverse(gt[i]);
}

int n, m;
int x[55], y[55], z[55];

ll solve() {
	ll res = 0;
	int minz = *min_element(z, z+n);

	FOR(t,minz-m,minz+m) {
		ll cur = 1;
		REP(i,n) {
			int need = abs(z[i] - t);
			if (need > m || (m - need) % 2) {
				cur = 0;
				break;
			}
			int rr = (m - need) / 2;
			cur = cur * C(m, rr) % MOD;
		}
		res = (res + cur) % MOD;
	}
	return res;
}


int go() {
	REP(i,n) z[i] = x[i] + y[i];
	ll res = solve();

	REP(i,n) z[i] = x[i] - y[i];
	res = res * solve() % MOD;

	return (int) res;
}

int main() {
	init();
	cin >> n;
	REP(i,n) cin >> x[i];
	REP(i,n) cin >> y[i];
	cin >> m;

	cout << go() << endl;
}

