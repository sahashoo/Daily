///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int l,r,x,y,k;cin>>l>>r>>x>>y>>k;
	for(int i=x;i<=y;i++){
		int a=k*i;
		if(a<=r&&a>=l)return cout<<"YES",0;
	}
	cout<<"NO";
}
