///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	ld ax,bx,cx,ay,by,cy;cin>>ax>>ay>>bx>>by>>cx>>cy;
	
	if((ax-bx)*(ax-bx)+(ay-by)*(ay-by)==(cx-bx)*(cx-bx)+(cy-by)*(cy-by)&&(ax-bx)/(ay-by)!=(bx-cx)/(by-cy))cout<<"Yes";
    else cout<<"No";
}
