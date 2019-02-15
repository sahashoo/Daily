///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define size(a) (long long)a.size()
using namespace std;
const int maxn=1e5+7,INF=2e18+7;
int f[256],g[256][256];

int32_t main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t;
	int n;cin>>n>>s>>t;
	int cnt=0,x=-1,y=-1;
	for(int i=0;i<n;i++)if(s[i]!=t[i])f[s[i]]=g[s[i]][t[i]]=i+1,cnt++;
	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			if(g[t[i]][s[i]]){
				x=i+1;
				y=g[t[i]][s[i]];
				break;
			}
			if(f[t[i]])x=i+1,y=f[t[i]];
		}
	}
	if(x!=-1){
		if(s[x-1]==t[y-1]&&s[y-1]==t[x-1])cnt-=2;
		else cnt--;
	}
	cout<<cnt<<'\n'<<x<<" "<<y;
}