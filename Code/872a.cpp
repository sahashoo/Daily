///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a=INF,b=INF,c=INF;
bool mrk[20];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0,x;i<n;i++){
		cin>>x;
		a=min(a,x);
		mrk[x]=true;
	}
	for(int i=0,x;i<m;i++){
		cin>>x;
		b=min(b,x);
		if(mrk[x]==true)c=min(x,c);
	}
	if(c!=INF)cout<<c;
	else cout<<min(a,b)<<max(a,b);
}
