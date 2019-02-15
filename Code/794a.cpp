///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,a,b,c,ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>a>>b>>c>>n;
	for(int i=0;i<n;i++){
		int d;cin>>d;
		if(d>b&&d<c)ans++;
	}
	cout<<ans;
}
