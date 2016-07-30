// Author: RR

// Algo:
// - The given condition is equivalent to:
//   S[i] = S[i+M]
// - Max |S| = 300
// - If M <= 17 --> brute force the first M character, then DP
// - If N/M <= 17 --> at most 17 group, brute force the flip k*M operations,
//   then solve using greedy

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

#define TWO(X) (1<<(X))
#define CONTAIN(S,X) (S & TWO(X))

int N, M;

int f[2][311];
string s;
int solve1() {
	int nGroup = N / M;
	if (N % M) ++nGroup;

	int res = N;
	REP(mask,TWO(M)) {
		int cur = 0;
		REP(i,M) if (s[i] == '1') cur |= TWO(i);
		f[0][0] = __builtin_popcount(cur ^ mask);
		f[1][0] = 1 + f[0][0];

		FOR(g,1,nGroup-1) {
			int nBit = M;
			if (g == nGroup-1 && N % M) nBit = N % M;

			int curMask = 0;
			REP(i,nBit) {
				int pos = g * M + i;
				if (s[pos] == '1')
					curMask |= TWO(i);
			}
			int diff0 = 0;
			REP(i,nBit) {
				int x = (mask >> i) & 1;
				int y = (curMask >> i) & 1;
				if (x != y) ++diff0;
			}
			int diff1 = nBit - diff0;

			f[0][g] = min(f[0][g-1] + diff0, f[1][g-1] + 1 + diff1);
			f[1][g] = min(f[1][g-1] + diff1, f[0][g-1] + 1 + diff0);

		}
		res = min(res, min(f[0][nGroup-1], f[1][nGroup-1]));

//		if (cur == mask) {
//			DEBUG(mask);
//			PR0(f[0], nGroup);
//			PR0(f[1], nGroup);
//		}
	}
	return res;
}

int flip[311], cnt[2][311];
int solve2() {
	int nGroup = N / M;
	if (N % M) ++nGroup;

	int res = N;
	REP(mask,TWO(nGroup)) {
		memset(flip, 0, sizeof flip);
		memset(cnt, 0, sizeof cnt);

		REP(i,nGroup) if (CONTAIN(mask,i)) {
			REP(j,i+1) flip[j] ^= 1;
		}
		FOR(i,0,N-1) {
			int x = s[i] - '0';
			if (flip[i / M]) x ^= 1;

			cnt[x][i % M]++;
		}

		int sum = __builtin_popcount(mask);
		REP(i,M) sum += min(cnt[0][i], cnt[1][i]);
		res = min(res, sum);
	}
	return res;
}

int main() {
    while (cin >> s >> M) {
		N = SZ(s);
		if (M <= 17) cout << solve1();
		else cout << solve2();
        cout << endl;
    }
}

