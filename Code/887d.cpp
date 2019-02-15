///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=3e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int t[maxn];
bool q[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,a,b,c,d,rate,len;cin>>n>>a>>b>>c>>d>>rate>>len;
	vector<int>T(n+2);T[0]=-1;;
	for(int i=0;i<n;i++)
		cin>>t[i]>>q[i],T[i+1]=t[i];;
	int mn=0,cur=0,j=0;
	for(int i=0;i<n;i++){
		while(j<n&&t[j]-t[i]<len)
			cur+=(q[j]?c:-d),mn=min(mn,cur),j++;
		if(rate+mn>=0)return cout<<T[i]+1,0;
		cur-=(q[i]?c:-d);
		mn-=(q[i]?c:-d);
		rate+=(q[i]?a:-b);
		if(rate<0)return cout<<-1,0;
	}
	cout<<T[n]+1;
}
