/*input
1
11 11
ooooooooooo
o.........o
o.ooooooo.o
o.o.....o.o
o.o.ooo.o.o
o.o.o.o.o.o
o.o.ooo.o.o
o.o.....o.o
o.ooooooo.o
o.........o
ooooooooooo
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

#define st first
#define nd second

typedef pair<int, int> ii;

int l[2005][2005], u[2005][2005], d[2005][2005];

int main() {
	int T, r, c;
	cin >> T;
	while(T--) {
		cin >> r >> c;
		int ans = 0;
		memset(l, 0, sizeof l);
		memset(u, 0, sizeof u);
		memset(d, 0, sizeof d);
		for(int i = 1; i <= r; ++i) for(int j = 1; j <= c; ++j) {
			char x;
			cin >> x;
			if(x == 'o') l[i][j] = l[i][j - 1] + 1;
			if(x == 'o') u[i][j] = u[i - 1][j] + 1;
		}
		for(int i = 1; i <= r; ++i) for(int j = 1; j <= c; ++j) if(l[i][j] >= 3 && u[i][j] >= 3) {
			for(int k = i - 1; k > i - u[i][j] + 1; --k) d[k][j] = -1, d[k][j - l[i][j] + 1] = 1;
		}
		for(int i = 1; i <= r; ++i) {
			int sum = 0;
			for(int j = 1; j <= c; ++j) sum += d[i][j], ans = max(ans, sum);
		}
		cout << ans << endl;
	}
}

