#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
vector<pair<ld,pair<int,pair<int,int> > > >a;
string str[MAXN];
int ans,ts,trm;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	
	int n;cin>>n;
	for(int i=0;i<n;i++){
		
		cin>>str[i];
		
		int h=0,s=0,sh=0;
		for(char c:str[i])
			if(c=='s')s++;
			else sh+=s,h++;
		
		if(h&&s){
			ld t=-((ld)s/h);
			a.pb({t,{h,{-s,-sh}}});
		}
		else if(s)ts+=s;
		else trm+=h;
		
	}
	
	sort(all(a));
	
	for(auto x:a){
		int s=-x.S.S.F;
		int h=x.S.F;
		int sh=-x.S.S.S;
		ans+= h*ts + sh;
		ts+=s;
	}
	
	cout<<ans+trm*ts;
	
	return cout<<endl,0;
}
