#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e5+7;
int f[MAXN],t[MAXN],a[MAXN],m[MAXN],cnt;
vector<int>p[MAXN];

int32_t main(){
	
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	for(int i=2;i<MAXN;i++)
		if(p[i].empty())
		for(int j=i;j<MAXN;j+=i)
			p[j].push_back(i);
	
	int n,q;cin>>n>>q;
	for(int i=1;i<=n;i++)
		cin>>a[i],f[i]=1;
	
	while(q--){
		int x;cin>>x;
		for(int i=0;i<(1<<p[a[x]].size());i++){
			if(i==0)m[i]=1;
			else m[i]=m[i&(i-1)]*p[a[x]][__builtin_ctz(i)];
			t[m[i]]-=(f[x]<0);
			if(__builtin_popcount(i)&1)cnt-=t[m[i]]*f[x];
			else cnt+=t[m[i]]*f[x];
			t[m[i]]+=(f[x]>0);
		}
		f[x]*=-1;
		cout<<cnt<<'\n';
	}
}