///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=5e5+7;
const int INF=1e9+7;
map<int,int>mp;
pair<int,pair<int,int> >a[MAXN];

bool cmp(pair<int,pair<int,int> > p,pair<int,pair<int,int> > q){
	if(p.F!=q.F)return p.F>q.F;
	if(p.S.F!=q.S.F)return p.S.F<q.S.F;
	if(p.S.S!=q.S.S)return p.S.S<q.S.S;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].F;
	for(int i=0;i<n;i++)cin>>a[i].S.F;
	for(int i=0;i<n;i++)cin>>a[i].S.S;
	sort(a,a+n,cmp);
	mp[INF]=-1;
	mp[-1]=INF;
	int ans=0;
	for(int i=0;i<n;i++){
		auto it=mp.upper_bound(a[i].S.F);
		if(it->S>a[i].S.S)ans++;
		else if(mp[a[i].S.F]<a[i].S.S){
			mp[a[i].S.F]=a[i].S.S;
			auto mpit=--mp.lower_bound(a[i].S.F);
			while(mpit->S<=a[i].S.S)mp.erase(mpit--);
		}
	}
	cout<<ans;
}
