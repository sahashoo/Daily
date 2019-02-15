///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,k,t,d,a,b,c;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>t>>k>>d;
	int m=(n+k-1)/k;
	int ans1=m*t,ans2=ans1;
	for(int i=0;i<=m;i++)ans2=min(ans2,max(d+(i*t),(m-i)*t));
	if(ans2<ans1)cout<<"YES";
	else cout<<"NO";
}
