#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	if(n*k>n*(n-1)/2)return cout<<-1,0;
	cout<<n*k<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=k;j++){
			int to=i+j;
			if(to>n)to-=n;
			cout<<i<<" "<<to<<'\n';
		}
	}
}