///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
string s,t,res;char c[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s>>t>>res;
	for(int i=0;i<s.size();i++){
		c[s[i]]=t[i];
		c[s[i]-32]=t[i]-32;
	}
	for(int i=0;i<res.size();i++){
		if(res[i]<65)cout<<res[i];
		else cout<<c[res[i]];
	}

}
