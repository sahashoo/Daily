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
int a[maxn];
map<int,int>d,p;
set<int>res;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(n==1)return cout<<-1,0;
	sort(a,a+n);
	for(int i=1,val;i<n;i++)val=a[i]-a[i-1],d[val]++,p[val]=i;
	int mnd=d.begin()->F,mxd=d.rbegin()->F;
	if(mxd==mnd){
		res.insert(a[0]-mnd);
		res.insert(a[n-1]+mxd);
		if(mnd%2==0&&n==2)res.insert(a[0]+mnd/2);
	}
	if(d.size()==2&&mxd==2*mnd&&d[mxd]==1)res.insert(a[p[mxd]]-mnd);
	cout<<res.size()<<"\n";
	for(auto x:res)cout<<x<<" ";
}
