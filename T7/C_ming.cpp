// Author: Ming
#include <bits/stdc++.h>
#define ff(i, a, b) for(int i = (a), _b = (b); i <= _b; i++)
#define fb(i, a, b) for(int i = (a), _b = (b); i >= _b; i--)
#define pb push_back

typedef long long ll;
using namespace std;
typedef vector <int> vi;

int N, M;
bool a[4096][4096];

int main(void) {
    cin >> M; N = 1 << M;
    ff(i, 0, N - 1) ff(j, 0, N - 1) if (__builtin_popcount(i ^ j) >= M / 2) a[i][j] = 1;
    vi v; ff(i, 0, N - 1) v.pb(i);
    ff(i, 0, N - 2) if (!a[v[i]][v[i+1]]) {
        ff(j, i + 2, N - 2) if (a[v[i]][v[j]] && a[v[i+1]][v[j+1]]) reverse(v.begin() + i + 1, v.begin() + j + 1);
    }
    ff(i, 0, N - 1) {
        ff(j, 0, M - 1) cout << (v[i] >> j & 1); cout << "\n";
    }
    return 0;
}
