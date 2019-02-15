///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=5007,INF=3e18+9237,mod=1e9+7;
pair<int,int>r[maxn],c[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int time=1;time<=k;time++){
		int t,i,col;cin>>t>>i>>col;
		if(t==1)r[i].F=time,r[i].S=col;
		else c[i].F=time,c[i].S=col;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(r[i].F>=c[j].F)cout<<r[i].S<<" ";
			else cout<<c[j].S<<" ";
		}
		cout<<endl;
	}
}
