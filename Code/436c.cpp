#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int N=20,K=1010;
char s[N][N][K];
int n,m,k,w,p[K],d[K][K],ans;
bool use[K][K],mrk[K];
vector<pair<int,int> > v,res;

void input(){
	cin>>n>>m>>k>>w;
	for(int i=0;i<k;i++){
		for(int j=0;j<n;j++){
			for(int o=0;o<m;o++){
				cin>>s[j][o][i];
			}
		}
	}
}

bool cmp(pair<int,int> a,pair<int,int> b){return d[a.F][a.S]<d[b.F][b.S];}

int par(int v){return v==p[v]?v:par(p[v]);}

bool merge(int u,int v){
	u=par(u),v=par(v);
	if(u==v)return false;
	p[u]=v;
	return true;
}

void graphmake(){
	for(int k1=0;k1<k;k1++){
		for(int k2=k1+1;k2<k;k2++){
			int cnt=0;
			for(int i=0;i<n;i++){
				for(int j=0;j<m;j++){
					if(s[i][j][k1]!=s[i][j][k2])cnt++;
				}
			}
			cnt*=w;
			d[k1][k2]=d[k2][k1]=cnt;
			v.push_back({k1,k2});
		}
	}
	for(int i=0;i<k;i++){
		d[k][i]=d[i][k]=n*m;
		v.push_back({i,k});
	}
	for(int i=0;i<=k;i++)p[i]=i;
	sort(v.begin(),v.end(),cmp);
	for(int i=0;i<v.size();i++){
		if(merge(v[i].F,v[i].S)){
			ans+=d[v[i].F][v[i].S];
			use[v[i].F][v[i].S]=use[v[i].S][v[i].F]=true;
		}
	}
}

void dfs(int v,int par){
	if(v!=k){
		if(par==k)res.push_back({v+1,0});
		else res.push_back({v+1,par+1});
	}
	mrk[v]=true;
	for(int i=0;i<k;i++)if(use[v][i]==true&&mrk[i]==false)dfs(i,v);
}


int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	input();
	graphmake();
	dfs(k,-1);
	cout<<ans<<endl;
	for(int i=0;i<res.size();i++)cout<<res[i].F<<" "<<res[i].S<<endl;
}
