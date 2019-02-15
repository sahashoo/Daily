///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
// #define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
// const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,m;
vector<pair<int,int> >e[3];
pair<int,int>g[maxn];

void input(){
	cin>>n>>m;
	for(int i=0,a,b;i<m;i++)
		cin>>a>>b,e[b].pb({a,i});//,mstw+=(b?a:0);
	sort(e[0].begin(),e[0].end());
	sort(e[1].begin(),e[1].end());
}

bool makeG(){
	int to=2;
	for(auto x:e[1])
		g[x.S]={1,to},to++;
	int u=2,v=3;
	for(auto x:e[0]){
		if(u==v)v++,u=2;
		if(e[1][u-2].F>x.F)return false;
		if(e[1][v-2].F>x.F)return false;
		g[x.S]={u,v};
		u++;
	}
	return true;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	input();
	if(makeG()==false)return cout<<-1,0;
	for(int i=0;i<m;i++)cout<<g[i].F<<" "<<g[i].S<<'\n';
}
