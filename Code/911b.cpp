#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a,b,ans=0;cin>>n>>a>>b;
	for(int i=1;i<n;i++){
		int num=min(a/i,b/(n-i));
		ans=max(ans,num);
	}
	cout<<ans;
}
