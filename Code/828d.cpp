///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
int n,k,h[maxn];
vector<int>res;
vector<pair<int,int> >g;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	int v=0;
	while(v+k<n-1){
		h[v+k]=h[v]+1;
		g.push_back({v,v+k});
		v++;
	}
	while(v<n-1){
		g.push_back({v,n-1});
		res.push_back(h[v]+1);
		v++;
	}
	sort(res.begin(),res.end(),greater<int>());
	cout<<res[0]+res[1]<<endl;
	for(auto x:g)cout<<x.F+1<<" "<<x.S+1<<endl;
}
