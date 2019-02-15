///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
char c[70][70];
bool mrk[70][70];
int cnt[70][70];
vector<pair<int,pair<int,int> > >lake;

void cng(int x,int y){
	c[x][y]='*';
	for(int i=0;i<4;i++)
		if(c[x+dx[i]][y+dy[i]]=='.')
			cng(x+dx[i],y+dy[i]);
}

int dfs(int x,int y){
	mrk[x][y]=true;
	cnt[x][y]++;
	for(int i=0;i<4;i++)
		if(mrk[x+dx[i]][y+dy[i]]==false)
			if(c[x+dx[i]][y+dy[i]]=='.')
				cnt[x][y]+=dfs(x+dx[i],y+dy[i]);
	return cnt[x][y];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];

	for(int i=1;i<=n;i++){
		if(mrk[i][1]==false&&c[i][1]=='.')dfs(i,1);
		if(mrk[i][m]==false&&c[i][m]=='.')dfs(i,m);
	}
	for(int i=1;i<=m;i++){
		if(mrk[1][i]==false&&c[1][i]=='.')dfs(1,i);
		if(mrk[n][i]==false&&c[n][i]=='.')dfs(n,i);
	}
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(mrk[i][j]==false&&c[i][j]=='.')
				lake.push_back({dfs(i,j),{i,j}});
			
	sort(lake.begin(),lake.end());
	int p=0,res=0;
	while(lake.size()-p>k)
		res+=lake[p].F,cng(lake[p].S.F,lake[p].S.S),p++;

	cout<<res<<'\n';
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++)cout<<c[i][j];
		cout<<'\n';
	}
}
