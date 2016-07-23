#include <bits/stdc++.h>
#define int long long
#define FOR(i,a,b) for(int i=(a),_b=(b); i<=_b; ++i)
#define FORD(i,a,b) for(int i=(a),_b=(b); i>=_b; --i)
#define REP(i,a) for(int i=0,_a=(a); i < _a; ++i)

#define DEBUG(X) { cout << #X << " = " << (X) << endl; }
#define PR(A,n)  { cout << #A << " = "; FOR(_,1,n) cout << A[_] << ' '; cout << endl; }
#define PR0(A,n) { cout << #A << " = "; REP(_,n) cout << A[_] << ' '; cout << endl; }

#define sqr(x) ((x) * (x))
#define ll long long
#define __builtin_popcount __builtin_popcountll
#define SZ(x) ((int) (x).size())
using namespace std;

double safe_sqrt(double x) {
    return sqrt(max((double)0.0,x));
}
int GI(ll& x) {
    return scanf("%lld", &x);
}

int f[1011][1011];
int n, a[1011];

#undef int
int main() {
#define int long long
    ios :: sync_with_stdio(0); cin.tie(0);
    cout << (fixed) << setprecision(9);
    while (cin >> n) {
        FOR(i,1,n) cin >> a[i];

        int inv = 0;
        FOR(i,1,n) FOR(j,i+1,n) if (a[i] > a[j]) ++inv;

        FOR(i,1,n) {
            // f[i][j] = số số > a[i], trong khoảng 1..j
            f[i][0] = 0;
            FOR(j,1,n) {
                f[i][j] = f[i][j-1];
                if (a[j] > a[i]) ++f[i][j];
            }
        }

        int res = inv;
        FOR(i,1,n) FOR(j,i+1,n) {
            // Đổi chỗ a[i], a[j]

            int cur = inv;
            cur -= (j - i) - (f[i][j] - f[i][i]);         // < a[i], in [i+1, j]
            cur -= f[j][j-1] - f[j][i];                   // > a[j], in [i+1, j-1]

            cur += f[i][j] - f[i][i];                     // > a[i], in [i+1, j]
            cur += (j - i - 1) - (f[j][j-1] - f[j][i]);   // < a[j], in [i, j-1]

            res = min(res, cur);
        }
        cout << res << endl;
    }
}
