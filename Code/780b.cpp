#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N=1e3+7,MOD=1e9+7,INF=1e18+7;
pair<string,string>a[N];
vector<int>g[N];
map<string,int>mp;
string res[N];
bool mrk[N];

void dfs(int v){
	mrk[v]=true;
	for(auto u:g[v]){
		if(res[u]!=""&&res[u]!=a[u].S)cout<<"NO",exit(0);
		res[u]=a[u].S;
		if(mrk[u]==false)dfs(u);
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		string s,t;cin>>s>>t;
		a[i]=make_pair(s.substr(0,3),s.substr(0,2)+t.substr(0,1));
		mp[a[i].F]++;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			if(a[j].F==a[i].S){
				g[i].push_back(j);
			}
		}
	}
	for(int i=0;i<n;i++)if(mp[a[i].F]>1)res[i]=a[i].S;
	for(int i=0;i<n;i++)if(res[i]!="")dfs(i);
	for(int i=0;i<n;i++)if(res[i]=="")res[i]=a[i].F;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(res[i]==res[j])return cout<<"NO",0;
		}
	}
	cout<<"YES"<<endl;
	for(int i=0;i<n;i++)cout<<res[i]<<'\n';
}
