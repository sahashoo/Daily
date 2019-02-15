///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7;
int n,sum,mn=INF;
int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a;cin>>a;
		if(a>0)sum+=a;
		if(a%2)mn=min(mn,abs(a));
	}
	if(sum%2)cout<<sum;
	else cout<<sum-mn;
}
