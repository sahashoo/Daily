#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxn=1e5+7;
typedef pair<int,int> pii;
typedef pair<int,char> pic;
queue<pii>Q;
vector<pair<int,pic> >ans;
pii pos[maxn];

bool cmp(pii &a,pii &b){
	return abs(a.F)+abs(a.S)<abs(b.F)+abs(b.S);
}

pic d(int x,int t){
	if(x==0)return {-1,'!'};
	if(t)return {abs(x),(x>0?'U':'D')};
	else return {abs(x),(x>0?'R':'L')};
}

int32_t main(){
	ios_base::sync_with_stdio(0);cout.tie(0);cin.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>pos[i].F>>pos[i].S;
	sort(pos,pos+n,cmp);
	for(int i=0;i<n;i++){
		pii tmp=pos[i];
		pic a=d(tmp.F,0);
		if(a.S!='!')ans.push_back({1,a});
		a=d(tmp.S,1);
		if(a.S!='!')ans.push_back({1,a});
		ans.push_back({2,{0,'!'}});
		a=d(-tmp.F,0);
		if(a.S!='!')ans.push_back({1,a});
		a=d(-tmp.S,1);
		if(a.S!='!')ans.push_back({1,a});
		ans.push_back({3,{0,'!'}});
	}
	cout<<ans.size()<<'\n';
	for(auto i:ans){
		if(i.F==1)cout<<i.F<<" "<<i.S.F<<" "<<i.S.S<<'\n';
		else cout<<i.F<<'\n';
	}
}