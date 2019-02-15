#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,a[maxn],A,sum;

int32_t main(){
	cin>>n>>A;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	for(int i=0;i<n;i++)cout<<a[i]-min(a[i],A-n+1)+max(1LL,A-sum+a[i])-1<<" ";
}