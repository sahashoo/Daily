///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
const int INF=3e18+9237;
const int maxn=500+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
vector<pair<char,pair<int,int> > >ans;
bool mrk[507][507];
char c[507][507];
pair<int,int>start;

void dfs(int x,int y){
	mrk[x][y]=true;
	ans.push_back({'B',{x,y}});
	for(int i=0;i<4;i++)
		if(mrk[x+dx[i]][y+dy[i]]==false&&c[x+dx[i]][y+dy[i]]=='.')
			dfs(x+dx[i],y+dy[i]);
	if(x!=start.F||y!=start.S){
		ans.push_back({'D',{x,y}});
		ans.push_back({'R',{x,y}});
	}
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(c[i][j]=='.'&&mrk[i][j]==false){
				start={i,j};
				dfs(i,j);
			}
		}
	}
	cout<<ans.size()<<"\n";
	for(auto x:ans)cout<<x.F<<" "<<x.S.F<<" "<<x.S.S<<'\n';
}
