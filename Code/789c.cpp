///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n,a[maxn],b[maxn],tmp,res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i)b[i-1]=abs(a[i-1]-a[i]);
	}
	for(int i=0;i<n;i++){
		int c=b[i];
		if(i%2==0)c*=-1;
		tmp+=c;
		res=max(res,tmp);
		tmp=max(tmp,(int)0);
	}
	tmp=0;
	for(int i=0;i<n;i++){
		int c=b[i];
		if(i%2)c*=-1;
		tmp+=c;
		res=max(res,tmp);
		tmp=max((int)0,tmp);
	}
	cout<<max(res,(int)0);
}
