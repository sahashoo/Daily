///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};
const int maxn=1e3+7;
char c[maxn][maxn];
int dst[maxn][maxn];
bool mrk[maxn][maxn][5],onQ[maxn][maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>c[i][j];
	int x1,x2,y1,y2;cin>>x1>>y1>>x2>>y2;
	
	queue<pair<int,int> >Q;Q.push({x1,y1});
	while(Q.size()){
		pair<int,int> v=Q.front();Q.pop();
		int X=v.F,Y=v.S;
		int t=dst[X][Y];
		for(int i=0;i<4;i++)
			for(int j=1;j<=k;j++){
				int x=X+dx[i]*j,y=Y+dy[i]*j;
				if(c[x][y]!='.'||mrk[x][y][i])break;
				mrk[x][y][i]=true;
				if(onQ[x][y]==false)
					dst[x][y]=t+1,Q.push({x,y}),onQ[x][y]=true;
			}
		if(X==x2&&Y==y2)return cout<<dst[X][Y],0;
	}
	cout<<-1;
}
