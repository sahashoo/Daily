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

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,l,r;cin>>n>>m;
	char c1,c2;
	string s;cin>>s;
	while(m--){
		cin>>l>>r>>c1>>c2;
		for(int i=l-1;i<r;i++)if(s[i]==c1)s[i]=c2;
	}
	cout<<s;
}
