///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e6+7,INF=1e18+7,mod=1e9+7;
int n,q,sgmnt[maxn],cnt[maxn],s[maxn];
vector<int>res,ans;

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void build(int ind=1,int l=1,int r=n){
	if(l==r){
		cnt[ind]=1;
		sgmnt[ind]=s[l];
		return ;
	}
	int mid=l+r>>1;
	build(ind*2,l,mid);
	build(ind*2+1,mid+1,r);
	sgmnt[ind]=gcd(sgmnt[ind*2],sgmnt[ind*2+1]);
	if(sgmnt[ind*2]==sgmnt[ind])cnt[ind]+=cnt[ind*2];
	if(sgmnt[ind*2+1]==sgmnt[ind])cnt[ind]+=cnt[ind*2+1];
}

void act(int x,int y,int ind=1,int l=1,int r=n){
	if(l>y||r<x)return ;
	if(x<=l&&r<=y)return res.push_back(ind);
	int mid=l+r>>1;
	act(x,y,ind*2,l,mid);
	act(x,y,ind*2+1,mid+1,r);
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>s[i];
	build();
	cin>>q;
	while(q--){
		int l,r;cin>>l>>r;
		act(l,r);
		int bmm=sgmnt[res[0]];
		for(auto i:res)bmm=gcd(bmm,sgmnt[i]);
		int t=0;
		for(auto i:res)if(bmm==sgmnt[i])t+=cnt[i];
		ans.push_back(r-l+1-t);
		res.clear();
	}
	for(auto x:ans)cout<<x<<endl;
}