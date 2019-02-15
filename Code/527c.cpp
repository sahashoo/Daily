#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
using namespace std;
const int N=1e5+7,INF=1e18+9235;
set<int>H,W;
set<pair<int,pair<int,int> > >stW,stH;

int32_t main() {
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int h,w,n;cin>>h>>w>>n;
	H.insert(0);H.insert(h);
	W.insert(0);W.insert(w);
	stH.insert({-h,{0,h}});
	stW.insert({-w,{0,w}});
	for(int i=0;i<n;i++){
		int x;char c;cin>>c>>x;
		if(c=='V'){
			set<int>::iterator it=H.upper_bound(x);
			int mx=(*it);
			it=H.lower_bound(x);it--;
			int mn=(*it);
			H.insert(x);
			stH.erase({-(mx-mn),{mn,mx}});
			stH.insert({-(x-mn),{mn,x}});
			stH.insert({-(mx-x),{x,mx}});
		}
		else{
			set<int>::iterator it=W.upper_bound(x);
			int mx=(*it);
			it=W.lower_bound(x);it--;
			int mn=(*it);
			W.insert(x);
			stW.erase({-(mx-mn),{mn,mx}});
			stW.insert({-(x-mn),{mn,x}});
			stW.insert({-(mx-x),{x,mx}});
		}
		cout<<((stW.begin()->F)*(stH.begin()->F))<<'\n';
	}
}