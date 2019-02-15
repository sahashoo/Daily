#include<bits/stdc++.h>
#define int long long
#define size(a) (int)a.size()
#define ld long double
using namespace std;
const int maxn=1e5+100,MOD=1e9+7,INF=1e18+7;

int32_t main(){
	string s,d;cin>>s>>d;
	int n=size(s),pos=0,q=0,POS=0;
	
	for(int i=0;i<n;i++)POS+=(s[i]=='+'?1:-1);
	for(int i=0;i<n;i++){
		if(d[i]=='?')q++;
		else pos+=(d[i]=='+'?+1:-1);
	}
	
	int dist=POS-pos;
	ld res=0.00;
	
	if((q+dist)%2==0&&q>=abs(dist)){
		int tmp=(q+abs(dist))/2,C=1;
		for(int i=0;i<tmp;i++)C*=q-i;
		for(int i=2;i<=tmp;i++)C/=i;
		res=(ld)C/(1<<q);
	}
	cout<<fixed<<setprecision(12)<<res;
	
}