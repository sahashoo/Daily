///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
char c[52][52];
bool a[52][52];

void dfs(int x,int y,int h,int X,int Y){
	a[x][y]=true;
	for(int i=0;i<4;i++)
		if(c[x][y]==c[x+dx[i]][y+dy[i]]&&(x+dx[i]!=X||y+dy[i]!=Y)){
			if(a[x+dx[i]][y+dy[i]]){
				if(h>3){
					cout<<"Yes\n";
					exit(0);
				}
			}
			else dfs(x+dx[i],y+dy[i],h+1,x,y);
		}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(!a[i][j])dfs(i,j,1,-1,-1);
	cout<<"No";
}