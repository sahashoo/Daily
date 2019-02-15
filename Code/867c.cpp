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
vector<pair<int,int> >a,b;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,S;cin>>n>>S;
	int suma=0,sumb=0,res=0;
	for(int i=0,A,B,s;i<n;i++){
		cin>>s>>A>>B;
		res+=max(A,B)*s;
		if(A>B)a.push_back({A-B,s}),suma+=s;
		else b.push_back({B-A,s}),sumb+=s;
	}
	sort(a.begin(),a.end());
	sort(b.begin(),b.end());
	int dsta=0,dstb=0,difa=suma%S,difb=sumb%S;
	if(difa+difb<=S&&difa&&difb){
		int p=0;
		while(difa){
			if(difa>=a[p].S)difa-=a[p].S,dsta+=a[p].S*a[p].F;
			else dsta+=difa*a[p].F,difa=0;
			p++;
		}
		p=0;
		while(difb){
			if(difb>=b[p].S)difb-=b[p].S,dstb+=b[p].S*b[p].F;
			else dstb+=difb*b[p].F,difb=0;
			p++;
		}
	}
	cout<<res-min(dsta,dstb);
}