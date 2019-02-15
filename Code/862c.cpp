#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int a[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,x;cin>>n>>x;
	if(n==1)return cout<<"YES\n "<<x,0;
	if(n==2&&x==0)return cout<<"NO\n ",0;
	if(n==2)return cout<<"YES\n0 "<<x,0;
	int sum=0;
	for(int i=1;i<n-2;i++)a[i]=i,sum^=i;
	if(sum==x)a[0]=(1<<17)|(1<<18),a[n-2]=(1<<17),a[n-1]=(1<<18);
	else a[0]=0,a[n-2]=(1<<17),a[n-1]=((1<<17)^x)^sum;
	cout<<"YES\n";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}