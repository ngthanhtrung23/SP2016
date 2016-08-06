#include <stdio.h>

int max(int a, int b){ return a>b?a:b; }

/// Segment tree
class segment_tree {
    int n;
    int T[50230997]; // maximum segment tree
    int lazy[50230997];
    void diffuse(int node, int ll, int rr);
    void update(int node, int ll, int rr, const int i, const int j, const int k);
    int query(int node, int ll, int rr, const int i, const int j);
public :
    void clear(int N);
    void update(int i, int j, int k);
    int query(int i, int j);
};

void segment_tree::diffuse(int node, int ll, int rr){
    if (lazy[node]==0) return;
    T[node] = lazy[node];
    if (ll<rr){
        lazy[node*2]=lazy[node];
        lazy[node*2+1]=lazy[node];
    }
    lazy[node]=0;
}

void segment_tree::update(int node, int ll, int rr, const int i, const int j, const int k){
    //printf("update(%d, %d, %d, %d, %d, %d)\n", node, ll, rr, i, j, k);
    diffuse(node, ll, rr);
    if (rr<i or ll>j or ll>rr) return;
    if (i<=ll && ll<=rr && rr<=j){
        lazy[node]=k;
        diffuse(node, ll, rr);
    }
    else {
        update(node*2, ll, (ll+rr)/2, i, j, k);
        update(node*2+1, (ll+rr)/2+1, rr, i, j, k);
        T[node] = max(T[node*2], T[node*2+1]);
    }
}

int segment_tree::query(int node, int ll, int rr, const int i, const int j){
    diffuse(node, ll, rr);
    if (rr<i or ll>j or ll>rr) return -1000111000;
    if (i<=ll && ll<=rr && rr<=j) return T[node];
    else {
        int d1=query(node*2, ll, (ll+rr)/2, i, j);
        int d2=query(node*2+1, (ll+rr)/2+1, rr, i, j);
        return max(d1, d2);
    }
}

void segment_tree::clear(int N){ n=N; for (int i=0; i<50230997; i++) T[i]=0; }
void segment_tree::update(int i, int j, int k){ update(1, 1, n, i, j, k); }
int segment_tree::query(int i, int j){
    int r = query(1, 1, n, i, j);
    //printf("query(%d, %d) = %d\n", i, j, r);
    return r;
}

/// Container
segment_tree tr; //
int m;

struct ii { int X, Y; };
ii b[230997];

main(){
    int i, p, q, r=0, t; //
    scanf("%d", &t);
while (t--){
    r=0;
    tr.clear(10111000);
    scanf("%d", &m);
    for (i=1; i<=m; i++){
        scanf("%d%d", &p, &q);
        b[i].X=p; b[i].Y=q;
        tr.update(p, q, -i);
    }
    for (i=1; i<=m; i++)
    if (tr.query(b[i].X, b[i].Y)==-i) r++;
    printf("%d\n", r);
}
}

