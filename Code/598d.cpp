#include<bits/stdc++.h>
using namespace std;
const int N=1e3+7;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
int n,m,k,cnt[N*N],col[N][N],cur;
char a[N][N];

int dfs(int x,int y,int cur){
	if(a[x][y]=='*'||col[x][y])return 0;
	col[x][y]=cur;
	int tmp=0;
	for(int i=0;i<4;i++)tmp+=(a[x+dx[i]][y+dy[i]]=='*');
	for(int i=0;i<4;i++)tmp+=dfs(x+dx[i],y+dy[i],cur);
	return tmp;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(col[i][j]==0&&a[i][j]=='.')cur++,cnt[cur]=dfs(i,j,cur);
		}
	}
	while(k--){
		int x,y;cin>>x>>y;
		cout<<cnt[col[x][y]]<<'\n';
	}
}