#include<bits/stdc++.h>
#define Q make_pair
using namespace std;
const int N=1507;
const int dx[]={1,-1,0,0};
const int dy[]={0,0,-1,1};
int n,m,sx,sy;
pair<int,int> flg[N][N];
bool mrk[N][N];
string c[N];//.[N];

void dfs(int x,int y)
{
	int X=(x%n+n)%n,Y=(y%m+m)%m;
	flg[X][Y]={x,y};
	for(int i=0;i<4;i++)
	{
		int a=x+dx[i],b=y+dy[i];//+m)%m;
		int A=(X+dx[i]+n)%n,B=(Y+dy[i]+m)%m;
		if(c[A][B]=='#')continue;
		if(flg[A][B]==Q(0,0))
			dfs(a,b);
		else if(flg[A][B]!=Q(a,b))
		{
			cout<<"Yes";
			exit(0);
		}
	}
}

int32_t main()
{
	cin>>n>>m;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		for(int j=0;j<m;j++)
		{
			// cin>>c[i][j];
			if(c[i][j]=='S')
				sx=i,sy=j,
				c[i][j]='.';
		}
	}
	dfs(sx,sy);
	cout<<"No";
}