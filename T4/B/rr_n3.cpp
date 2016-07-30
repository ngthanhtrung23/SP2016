#include <iostream>
#include <cstdio>
using namespace std;

int m, n;
char a[2011][2011];

void erase(int r1, int c1, int r2, int c2) {
    for (int r = r1; r <= r2; r++) a[r][c1] = a[r][c2] = '.';
    for (int c = c1; c <= c2; c++) a[r1][c] = a[r2][c] = '.';
}

int best(int r1, int c1, int r2, int c2) {
    int res = 0;
    for (int r = r1; r <= r2; r++)
        for (int c = c1; c <= c2; c++) if (a[r][c] == 'o') {
            int rr = r;
            int cc = c;
            while (cc + 1 < n && a[rr][cc + 1] == 'o') cc++;
            while (rr + 1 < m && a[rr + 1][cc] == 'o') rr++;
            erase(r, c, rr, cc);
            res = max(res, best(r + 1, c + 1, rr - 1, cc - 1) + 1);
        }
    return res;
}

int main() {
    int nTest;
    cin >> nTest;
    while (nTest--) {
        cin >> m >> n;
        for (int i = 0; i < m; i++) cin >> a[i];
        cout << best(0, 0, m - 1, n - 1) << endl;
    }
}
