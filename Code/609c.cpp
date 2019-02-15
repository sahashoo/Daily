#include<bits/stdc++.h>
#define ld long double
using namespace std;
const int maxn=1e5+7;
int a[maxn],sum;
ld avr;

int32_t main(){
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],sum+=a[i];
	int t=sum%n,cmp=sum/n;
	sort(a,a+n,greater<int>());
	int res=0;
	for(int i=0;i<n;i++)res+=abs(a[i]-(i<t?cmp+1:cmp));
	cout<<res/2;
}