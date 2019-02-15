#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=2e5+7;
const int INF=1e9+10;
int n,m,ans,rn=INF,rm=INF,ln=-INF,lm=-INF;

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++){
	    int l,r;cin>>l>>r;
        ln=max(ln,l);
        rn=min(rn,r);
	}
	cin>>m;
	for(int i=1;i<=m;i++){
	    int l,r;cin>>l>>r;
        lm=max(lm,l);
        rm=min(rm,r);
	}
    ans=max(lm-rn,ln-rm);
    if(ans<0)cout<<0<<endl;
    else cout<<ans<<endl;
}
