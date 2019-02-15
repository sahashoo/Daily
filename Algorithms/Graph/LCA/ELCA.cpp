#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1010, MAXMASK = 1 << 10;
vector<int> g[MAXN];
int LBIT[MAXMASK], RBIT[MAXMASK], preorder[MAXN], I[MAXN], A[MAXN], par[MAXN];

pair< int, int > dfs1(int v, int p, int &&timer) {
    I[v] = preorder[v] = ++timer;
    pair< int, int & > res(RBIT[I[v]], I[v]);
	for (int to : g[v])
		if(to!=p)
        res = max< pair< int, int > >(res, dfs1(to, v, (int &&)(timer)));
    par[I[v]] = p;
    return res;
}

void dfs2(int v, int up,int p) {
    A[v] = up | RBIT[I[v]];
    for (int to : g[v])
		if(p!=to)
        dfs2(to, A[v],v);
}

void preprocess(int root) {
    for (int i = 1; i < MAXMASK; i <<= 1)
        fill(LBIT + i, LBIT + i + i, i);
	for (int i = 1; i < MAXMASK; RBIT[i] = i, i <<= 1)
        copy(RBIT + 1, RBIT + i, RBIT + i + 1);
	dfs1(root, -1, 0);
	dfs2(root, 0,root);
}

inline int enter_into_strip(int x, int hz) {
    if (RBIT[I[x]] == hz)
        return x;
    int hw = LBIT[A[x] & (hz - 1)];
    return par[(I[x] & (~hw + 1)) | hw];
}

inline int lca(int x, int y) {
    int hb = I[x] == I[y] ? RBIT[I[x]] : LBIT[I[x] ^ I[y]]; // Not a bug
    int hz = RBIT[A[x] & A[y] & (~hb + 1)];
    int ex = enter_into_strip(x, hz);
    int ey = enter_into_strip(y, hz);
    return preorder[ex] < preorder[ey] ? ex : ey;
}

int32_t main(){
	int n;cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	/*
		G=
			7
			1 2
			1 3
			2 4
			2 5
			3 6
			3 7
	*/
	preprocess(1);
	cout<<lca(4,7)<<endl;
	cout<<lca(6,7)<<endl;
	cout<<lca(4,5)<<endl;
}