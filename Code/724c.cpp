///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,m,q,x,y,k,d=n,t[2][2][maxn];
bool mrk[2][2][maxn];
vector<int>ans;

void F(){
	d%=2*m;
	x=1-x;
	while(1){
		if(k==0&&y+d<=m){y+=d;break;}//return y+=d;
		if(k==1&&y-d>=0){y-=d;break;}//return y-=d;
		if(k==0)d-=m-y,y=m,k=1;
		else if(k==1)d-=y,y=0,k=0;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	memset(t,-1,sizeof(t));
	int cnt=0;
	while(mrk[k][x][y]==false){
		mrk[k][x][y]=true;
		t[1-k][x][y]=cnt*n;
		if(cnt!=0&&(y==0||y==m))break;
		d=n;
		F();
		cnt++;
	}
	cin>>q;
	for(int i=0;i<q;i++){
		int a,b,res=INF;cin>>a>>b;
		
		x=0,y=b,k=0,d=n-a;
		F();
		if(t[k][x][y]!=-1)res=min(res,t[k][x][y]+n-a);
		
		x=1,y=b,k=0,d=a;
		F();
		if(t[k][x][y]!=-1)res=min(res,t[k][x][y]+a);
		
		x=0,y=b,k=1,d=n-a;
		F();
		if(t[k][x][y]!=-1)res=min(res,t[k][x][y]+n-a);
		
		x=1,y=b,k=1,d=a;
		F();
		if(t[k][x][y]!=-1)res=min(res,t[k][x][y]+a);
		
		if(res==INF)ans.push_back(-1);
		else ans.push_back(res);
	}
	for(auto x:ans)cout<<x<<endl;
}
