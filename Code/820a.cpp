#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e9+7;
const int INF=1e9+7;
int v,l,vmax,a,today,c;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>c>>v>>vmax>>a>>l;
    for(int i=0;i<maxn;i++){
        today=min(v+(a*i),vmax);
        if(i)today-=l;
        c-=today;
        if(c<=0)return cout<<i+1,0;
    }

}
