///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
string s,ans;
int cnt,n;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>s;s+='0';
	for(int i=0;i<=n;i++){
		if(s[i]=='0')ans+=(char)cnt+'0',cnt=0;
		else cnt++;
	}
	cout<<ans;
}
