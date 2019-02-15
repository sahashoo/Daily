#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int a[MAXN],b[MAXN],c,res;

bool check(int x){
	int sum=0,temp=c;
	for(int i=0;i<x;i++)
		temp-=max(b[x-i-1]-a[i],0ll),
		sum+=min(a[i],b[x-i-1]);
	if(temp<0)return false;
	res=sum-temp;
	return 1;
}

int32_t main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m>>c;
	for(int i=0;i<n;i++)
		cin>>a[i];
	for(int i=0;i<m;i++)
		cin>>b[i];
	sort(b,b+m);
	sort(a,a+n,greater<int>());
	m=min(n,m);
	n=min(n,m);
	int l=0,r=n+1;
	while(r-l>1){
		int mid=(l+r)/2;
		(check(mid)?l:r)=mid;
	}
	cout<<l<<" "<<max(0ll,res)<<endl;
}