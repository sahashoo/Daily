#include<bits/stdc++.h>
#define ld long double
#define int long long
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
ld r,rlx[MAXN];
int x[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n>>r;
	for(int i=0;i<n;i++){
		cin>>x[i];
		ld mxy=r;
        for(int j=0;j<i;j++){
            ld dst=4.0*r*r-1.0*abs(x[i]-x[j])*abs(x[i]-x[j]);
            if(dst>=0.0)mxy=max(mxy,sqrt(dst)+rlx[j]);
		}
		rlx[i]=mxy;
    }
	for(int i=0;i<n;i++)
		cout<<fixed<<setprecision(10)<<rlx[i]<<" ";
}
