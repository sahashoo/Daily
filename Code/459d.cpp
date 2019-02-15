#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int n,a[maxn],Pfx[maxn],Sfx[maxn],T[maxn];
map<int,int>mp,mp1;

void add(int pos){
	for(int i=pos;i<=n;i+=(i&(-i)))T[i]++;
}

int sum(int pos){
	int tmp=0;
	for(int i=pos;i>0;i-=(i&(-i)))tmp+=T[i];
	return T[0]+tmp;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)mp[a[i]]++,Pfx[i]=mp[a[i]];
	for(int i=n-1;i>=0;i--)mp1[a[i]]++,Sfx[i]=mp1[a[i]];
	int res=0;
	for(int i=n-1;i>=0;i--)res+=sum(Pfx[i]-1),add(Sfx[i]);
	cout<<res;
}