///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int a,b,b1,n,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>a>>b;
	for(int i=0;i<n;i++){
		int p;cin>>p;
		if(p==2){
			if(b>=1)b--;
			else ans+=2;
		}
		if(p==1){
			if(a>=1)a--;
			else if(b>=1)b--,b1++;
			else if(b1>=1)b1--;
			else ans++;
		}
	}
	cout<<ans;
}
