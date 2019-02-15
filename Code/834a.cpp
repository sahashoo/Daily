#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;
map<char,int>mp;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	mp['^']=0;mp['>']=1;mp['v']=2;mp['<']=3;
	char s,e;cin>>s>>e;
	int n;cin>>n;
	if(s==e||(mp[s]+6)%4==mp[e])return cout<<"undefined",0;
	if((mp[e]+1)%4==mp[s]){
		if(n%4==3)cout<<"cw";
		if(n%4==1)cout<<"ccw";
	}
	if((mp[s]+1)%4==mp[e]){
		if(n%4==3)cout<<"ccw";
		if(n%4==1)cout<<"cw";
	}
}