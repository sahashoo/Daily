///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
#define PAIR pair<int,int>
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,res;
map<int,int>a,b;
map<PAIR,int>t;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;cin>>x>>y;
		a[x]++;b[y]++;
		t[{x,y}]++;
	}
	for(auto it:a)res+=(it.S)*(it.S-1)/2;
	for(auto it:b)res+=(it.S)*(it.S-1)/2;
	for(auto it:t)res-=(it.S)*(it.S-1)/2;
	cout<<res;
}
