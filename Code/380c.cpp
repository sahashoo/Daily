#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+7;
int a[maxn],b[maxn],c[maxn],n,q,open,close,res;
vector<int>ans;
string s;

void build(int ind=1,int l=1,int r=n){
	if(l==r){
		if(s[l-1]=='(')b[ind]=1;
		else c[ind]=1;
		return ;
	}
	int mid=(l+r)/2,lc=ind*2,rc=ind*2+1;
	build(lc,l,mid);
	build(rc,mid+1,r);
	int t=min(b[lc],c[rc]);
	a[ind]=a[lc]+a[rc]+2*t;
	b[ind]=b[rc]+b[lc]-t;
	c[ind]=c[rc]+c[lc]-t;
}

void act(int x,int y,int ind=1,int l=1,int r=n){
	//cout<<l<<" "<<r<<endl;
	if(x>r||y<l)return ;
	if(y>=r&&x<=l){
		int t=min(open,c[ind]);
		res+=a[ind]+(2*t);
		open+=b[ind]-t;
		close+=c[ind]-t;
		return ;
	}
	int mid=(l+r)/2;
	act(x,y,ind*2,l,mid);
	act(x,y,ind*2+1,mid+1,r);
}

int32_t main(){
	cin>>s;n=s.size();
	build();
	cin>>q;;
	for(int i=0;i<q;i++){
		int l,r;cin>>l>>r;
		act(l,r);
		ans.push_back(res);
		res=0;open=0;close=0;
	}
	for(auto x:ans)cout<<x<<endl;
}