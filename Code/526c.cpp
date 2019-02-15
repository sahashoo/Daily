#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int c,h1,h2,w1,w2;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>c>>h1>>h2>>w1>>w2;
	int m=(int)sqrt(c);
	int ans=0;
	for(int i=0;i<=m;i++){
		if(i*w1<=c)ans=max(ans,i*h1+(c-i*w1)/w2*h2);
		if(i*w2<=c)ans=max(ans,i*h2+(c-i*w2)/w1*h1);
	}
	cout<<ans;
}
