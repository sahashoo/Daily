///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=107;
char c[N][N];
int n,m,cnt,ans,l=N,r,u=N,d;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			cin>>c[i][j];
			if(c[i][j]=='B'){
				cnt++;
				l=min(l,j);r=max(r,j);
				d=max(i,d);u=min(u,i);
			}
		}
	}
	ans=max(d-u+1,r-l+1);
	if(ans>n||ans>m)return cout<<-1,0;
	if(cnt==n*m&&n!=m)return cout<<-1,0;
	if(cnt==0)return cout<<1,0;
	cout<<(ans*ans)-cnt<<endl;
	//cout<<l<<" "<<r<<" "<<u<<" "<<d<<" "<<ans;
}
