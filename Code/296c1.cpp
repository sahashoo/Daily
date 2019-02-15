#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a[N],b[N][3],c[N],d[N],e[N],f[N];

int32_t main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<m;i++)cin>>b[i][0]>>b[i][1]>>b[i][2];
	for(int i=0,l,r;i<k;i++)cin>>l>>r,c[l-1]++,c[r]--;
	d[0]=c[0];
	b[0][2]*=d[0];
	for(int i=1;i<m;i++)d[i]=d[i-1]+c[i],b[i][2]*=d[i];
	for(int i=0;i<m;i++)e[b[i][0]-1]+=b[i][2],e[b[i][1]]-=b[i][2];
	f[0]=e[0];
	for(int i=1;i<n;i++)f[i]=f[i-1]+e[i];
	for(int i=0;i<n;i++)cout<<a[i]+f[i]<<" ";
}