#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int n,d,mxp,dp[maxn],flg[maxn],sgmnt[maxn*4],par[maxn];
pair<int,int>h[maxn];

void fnd(int L,int R,int v=1,int l=1,int r=n){
	if(L>h[r].F||R<h[l].F)return ;
	if(L<=h[l].F&&R>=h[r].F){
		if(dp[mxp]<dp[sgmnt[v]])mxp=sgmnt[v];
		return ;
	}
	int mid=l+r>>1;
	fnd(L,R,v*2,l,mid);
	fnd(L,R,v*2+1,mid+1,r);
}
/*
void update(int L,int R,int v=1,int l=1,int r=n){
	if(l>L||r<L)return ;
	if(l==r){
		sgmnt[v]=R;
		return ;
	}
	int mid=l+r>>1;
	update(L,R,v*2,l,mid);
	update(L,R,v*2+1,mid+1,r);
	if(dp[sgmnt[v*2]]<dp[sgmnt[v*2+1]])sgmnt[v]=sgmnt[v*2+1];
	else sgmnt[v]=sgmnt[v*2];
}*/

void update(int L,int R,int v=1,int l=1,int r=n){
	if(l>L||r<L)return ;
	if(l==r){
		sgmnt[v]=R;
		return ;
	}
	int mid=l+r>>1;
	update(L,R,v*2,l,mid);
	update(L,R,v*2+1,mid+1,r);
	sgmnt[v]=sgmnt[v*2+1];
	if(dp[sgmnt[v]]<dp[sgmnt[v*2]])sgmnt[v]=sgmnt[v*2];
}

int32_t main(){
	cin>>n>>d;
	for(int i=1;i<=n;i++)cin>>h[i].F,h[i].S=i;
	sort(h+1,h+n+1);
	for(int i=1;i<=n;i++)flg[h[i].S]=i;
	for(int i=n;i>0;i--){
		mxp=0;
		fnd(h[flg[i]].F+d,INF);
		fnd(-INF,h[flg[i]].F-d);
		dp[i]=dp[mxp]+1;
		par[i]=mxp;
		update(flg[i],i);
	}
	int tmp=0;
	for(int i=1;i<=n;i++)if(dp[tmp]<dp[i])tmp=i;
	cout<<dp[tmp]<<endl;
	while(tmp){
		cout<<tmp<<" ";
		tmp=par[tmp];
	}
}