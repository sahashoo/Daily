/// read! read! read! read! read! read!
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
const int INF=1e9+421;
set<pair<int,int> >st;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,q;cin>>n>>q;
	int ans=n;
	while(q--){
		int l,r,k;cin>>l>>r>>k;
		auto x=st.lower_bound({l,0});
		while(x!=st.end()){
			int R=(*x).F,L=(*x).S;
			int fas=min(r,R)-max(l,L)+1;
			if(fas<=0)break;
			ans+=fas;
			st.erase(x++);
			if(L<l)st.insert({l-1,L});
			if(R>r)st.insert({R,r+1});
		}
		if(k==1)st.insert({r,l}),ans-=r-l+1;
		cout<<ans<<'\n';
	}
}