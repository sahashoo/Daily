#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
int n,m,k,a[N],sgmnt[N*10],lzy[N*10],ql[N],qr[N],d[N],arr[N];

void update(int L,int R,int v=1,int l=1,int r=m){
	if(R<l||L>r)return ;
	if(l==r){sgmnt[v]++;return ;}
	if(L<=l&&R>=r){lzy[v]++;return ;}
	int mid=l+r>>1;
	update(L,R,v*2,l,mid);
	update(L,R,v*2+1,mid+1,r);
}

void output(int v=1,int l=1,int r=m){
	if(l==r){
		sgmnt[v]+=lzy[v];
		d[l]*=sgmnt[v];
		return ;
	}
	int mid=l+r>>1;
	lzy[v*2]+=lzy[v];
	lzy[v*2+1]+=lzy[v];
	output(v*2,l,mid);
	output(v*2+1,mid+1,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++)cin>>ql[i]>>qr[i]>>d[i];
	for(int i=1,l,r;i<=k;i++)cin>>l>>r,update(l,r);
	output();
	for(int i=1;i<=m;i++)arr[ql[i]]+=d[i],arr[qr[i]+1]-=d[i];
	int partial=0;
	for(int i=1;i<=n;i++)partial+=arr[i],cout<<a[i]+partial<<" ";
}