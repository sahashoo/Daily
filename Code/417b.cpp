#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
set<pair<int,int> >s;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	bool ans=true;
	for(int i=0;i<n;i++){
		int x,k;cin>>x>>k;
		if(x==0)s.insert({x,k});
		else if(s.count({x-1,k}))s.insert({x,k});
		else ans=false;
	}
	cout<<(ans?"YES":"NO");
}
