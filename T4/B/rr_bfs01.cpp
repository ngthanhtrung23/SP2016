#include <bits/stdc++.h>
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

char tmp[2011];
int a[2011][2011];
int f[2011][2011];
const int di[4] = {-1,1,0,0};
const int dj[4] = {0,0,-1,1};

int main() {
    int ntest; cin >> ntest;
    FOR(test,1,ntest) {
        int m, n;
        scanf("%d%d\n", &m, &n);
        memset(a, 0, sizeof a);
        memset(f, -1, sizeof f);
        FOR(i,1,m) {
            scanf("%s\n", &tmp[0]);
            FOR(j,1,n)
                if (tmp[j-1] == '.') a[i][j] = 0;
                else a[i][j] = 1;
        }
        ++m; ++n;

        f[0][0] = 0;
        deque< pair<int,int> > qu;
        qu.push_front(make_pair(0, 0));
        while (!qu.empty()) {
            auto p = qu.front(); qu.pop_front();
            int u = p.first, v = p.second;
            REP(dir,4) {
                int uu = u + di[dir], vv = v + dj[dir];
                if (uu < 0 || vv < 0 || uu > m || vv > n) continue;
                if (f[uu][vv] >= 0) continue;

                if (a[uu][vv]) {
                    qu.push_back(make_pair(uu, vv));
                    f[uu][vv] = f[u][v] + 1;
                }
                else {
                    f[uu][vv] = f[u][v];
                    qu.push_front(make_pair(uu, vv));
                }
            }
        }

        int res = 0;
        FOR(i,1,m) FOR(j,1,n) res = max(res, f[i][j]);
        cout << res << endl;
    }
}

