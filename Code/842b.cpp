///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define ld long double
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int r,d,n;cin>>r>>d>>n;
	int cnt=0;
	for(int i=0;i<n;i++){
		int x,y,ri;cin>>x>>y>>ri;
		ld f=(ld)sqrt(pow(x,2)+pow(y,2));
		if(f>=ri+r-d&&f<=r-ri)cnt++;
	}
	cout<<cnt;
}
