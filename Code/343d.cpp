#include<bits/stdc++.h>
using namespace std;
const int MAXN=5e5+7;
vector<int>g[MAXN];
int trm[MAXN],bgn[MAXN],n,ord;

struct node{
	int lzy,tf,tc;
}seg[4*MAXN];

void post_ord(int v,int p){
	bgn[v]=ord++;
	for(int u:g[v])
		if(u!=p)post_ord(u,v);
	trm[v]=ord;
}

void shift(int v,int l,int r){
	if(seg[v].lzy==0)return;
	int lc=v*2,rc=lc+1;
	seg[v].tf=seg[v].lzy;
	if(r-l>1){
		seg[lc].lzy=seg[v].lzy;
		seg[rc].lzy=seg[v].lzy;
	}
	seg[v].lzy=0;
}

void _fill(int x,int y,int t,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(x>=r||y<=l)return;
	if(l>=x&&r<=y){
		seg[v].lzy=t;
		shift(v,l,r);
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	_fill(x,y,t,lc,l,mid);
	_fill(x,y,t,rc,mid,r);
	seg[v].tf=max(seg[lc].tf,seg[rc].tf);
}

void _clear(int x,int t,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(r-l<=1){
		seg[v].tc=t;
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	if(x<mid)_clear(x,t,lc,l,mid);
	else _clear(x,t,rc,mid,r);
	seg[v].tc=max(seg[lc].tc,seg[rc].tc);
}

int status(int x,int y,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(x>=r||y<=l)return -1;
	if(l>=x&&r<=y)return seg[v].tc;
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	return max(status(x,y,lc,l,mid),status(x,y,rc,mid,r));
}

int condition(int x,int v=1,int l=0,int r=n){
	shift(v,l,r);
	if(r-l<=1)return seg[v].tf;
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	if(x<mid)return condition(x,lc,l,mid);
	else return condition(x,rc,mid,r);
}

void build(int v=1,int l=0,int r=n){
	seg[v]=node();
	if(r-l<=1)return;
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	build(lc,l,mid);
	build(rc,mid,r);
}

// void output(){
	// cout<<"segment is : \n-------tc : ";
	// for(int i=1;i<15;i++)
		// cout<<seg[i].tc<<' ';cout<<"\n";
	// cout<<"-------tf : ";
	// for(int i=1;i<15;i++)
		// cout<<seg[i].tf<<' ';cout<<'\n';
// }

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++){
		int u,v;cin>>u>>v;
		g[v].push_back(u);
		g[u].push_back(v);
	}
	post_ord(1,0);
	build();
	int q;cin>>q;
	for(int i=1;i<=q;i++){
		int type,v;cin>>type>>v;
		if(type==1)_fill(bgn[v],trm[v],i);
		if(type==2)_clear(bgn[v],i);
		if(type==3){
			int alpha=status(bgn[v],trm[v]);
			int beta=condition(bgn[v]);
			cout<<(alpha>=beta?"0":"1")<<'\n';
		}
		// output();
	}
}