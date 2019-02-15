///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=100,INF=1e18+9237,mod=1e9+7;
int a[maxn][5];
string s[maxn];
map<char,int>mp;

int type(char c){
	if(c<'0')return 1;
	if(c>'9')return 2;
	return 3;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>s[i];

	for(int i=0;i<n;i++){
		a[i][1]=a[i][2]=a[i][3]=INF;
		for(int j=0;j<m;j++){
			int tp=type(s[i][j]),pos=min(m-j,j);
			a[i][tp]=min(a[i][tp],pos);
		}
	}
	int ans=INF;
	for(int x=0;x<n;x++){
		for(int y=0;y<n;y++){
			for(int z=0;z<n;z++){
				if(a[x][1]+a[y][2]+a[z][3]<INF){
					if(x!=y&&y!=z&&z!=x){
						ans=min(ans,a[x][1]+a[y][2]+a[z][3]);
					}
				}
			}
		}
	}
	cout<<ans;
}
