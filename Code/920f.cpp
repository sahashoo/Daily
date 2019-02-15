#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
// const int INF=3e18+9237;
const int MAXN=3e5+7;
const int mod=1e9+7;
const int sqN=1e6+7;
const int lgN=20;
int n,p[sqN],a[MAXN],seg[4*MAXN];
bool is12[MAXN*4];

void build(int v=1,int l=0,int r=n){
	if(r-l<=1){
		seg[v]=a[l];
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	build(lc,l,mid);
	build(rc,mid,r);
	seg[v]=seg[lc]+seg[rc];
}

void update(int x,int y,int v=1,int l=0,int r=n){
	if(x>=r||y<=l||is12[v])return;
	if(r-l<=1){
		seg[v]=p[seg[v]];
		is12[v]=(seg[v]==p[seg[v]]);
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	update(x,y,lc,l,mid);
	update(x,y,rc,mid,r);
	seg[v]=seg[lc]+seg[rc];
	is12[v]=is12[lc]&&is12[rc];
}

int query(int x,int y,int v=1,int l=0,int r=n){
	if(x>=r||y<=l)return 0;
	if(x<=l&&y>=r)return seg[v];
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	return query(x,y,lc,l,mid)+query(x,y,rc,mid,r);
}

void D(){
	for(int i=1;i<sqN;i++)
		for(int j=i;j<sqN	;j+=i)
			p[j]++;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int tp,l,r,q;
	cin>>n>>q;
	for(int i=0;i<n;i++)cin>>a[i];
	build();
	D();
	while(q--){
		cin>>tp>>l>>r;
		if(tp==1)update(l-1,r);
		else cout<<query(l-1,r)<<'\n';
	}
}