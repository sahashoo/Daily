/// read! read! read! read! read! read!
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
int a[MAXN],fib[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	fib[0]=fib[1]=1;
	for(int i=2;i<n;i++)
		fib[i]=fib[i-1]+fib[i-2];
	int ind=0;
	while(ind<n){
		if(k<=fib[n-ind-1])
			a[ind++]=ind;
		else{
			k-=fib[n-ind-1];
			a[ind]=ind+2;
			a[ind+1]=ind+1;
			ind+=2;
		}
	}
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}