#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
int m,b,ans;

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>m>>b;
	for(int y=0;y<=b;y++){
		int x=(y-b)*m*-1;
		int maxx=(y+1)*x*(x+1)/2;
		int maxy=(y+1)*y*(x+1)/2;
		ans=max(ans,maxx+maxy);
	}
    cout<<ans<<endl;
}
