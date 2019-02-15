///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=1e4+7;//,INF=3e18+9237,mod=1e9+7;
int a[N+1];


int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	bool ans=false;
	for(int i=0;i<m;i++){
		int k;cin>>k;
		bool flg=false;
		for(int j=0,x;j<k;j++){
			cin>>x;
			if(a[abs(x)]==0)a[abs(x)]=x;
			if(a[abs(x)]==-x)flg=true;
		}
		if(flg==false)ans=true;
		if(ans==false)memset(a,0,sizeof(a));
	}
	cout<<(ans?"YES":"NO");
}
