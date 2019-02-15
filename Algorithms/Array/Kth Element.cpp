#include<bits/stdc++.h>
using namespace std;
// const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
vector<int>seg[4*MAXN],Q;
int a[MAXN],n;

void _merge(int v,int lc,int rc){
	int lcln=seg[lc].size(),rcln=seg[rc].size();
	int i=0,j=0;
	while(i<lcln||j<rcln){
		if(i==lcln){
			seg[v].push_back(seg[rc][j]);
			j++;
		}
		else if(j==rcln){
			seg[v].push_back(seg[lc][i]);
			i++;
		}
		else if(seg[rc][j]>seg[lc][i]){
			seg[v].push_back(seg[lc][i]);
			i++;
		}
		else{
			seg[v].push_back(seg[rc][j]);
			j++;
		}
	}
}

void build(int v=1,int l=0,int r=n){
	if(r-l<=1){
		seg[v].push_back(a[l]);
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	build(lc,l,mid);
	build(rc,mid,r);
	_merge(v,lc,rc);
}

void store_in_q(int x,int y,int v=1,int l=0,int r=n){
	if(y<=l||r<=x)return ;
	if(l>=x&&r<=y){
		Q.push_back(v);
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	store_in_q(x,y,lc,l,mid);
	store_in_q(x,y,rc,mid,r);
}

int kth_element(int k,int x,int y){//all 0_base
	Q.clear();
	store_in_q(x,y);
	int i=0; 
	while(i<Q.size()){
		int v=Q[i++];
		if(k>=seg[v].size()){
			k-=seg[v].size();
		}
		else {
			return seg[v][k];
		}
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	build();
	int tq;cin>>tq;
	while(tq--){
		int l,r,x;cin>>l>>r>>x;
		cout<<kth_element(x-1,l-1,r)<<endl;
	}
}