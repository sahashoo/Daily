///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int a[maxn],b[maxn],k,n,ans=INF,pos,p;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k>>p;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=k;i++)cin>>b[i];
	sort(a+1,a+n+1);
	sort(b+1,b+k+1);
	for(int i=0;i<=k-n;i++){
		int cnt=0;
		for(int j=1;j<=n;j++){
			cnt=max(abs(a[j]-b[i+j])+abs(b[i+j]-p),cnt);
		}
		ans=min(ans,cnt);
	}
	cout<<ans;
}
