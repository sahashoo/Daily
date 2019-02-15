#include<bits/stdc++.h>
#define int long long
#define S second
#define F first
using namespace std;
const int maxn=1e5+7,INF=1e14+7;
int sum[maxn];//,a[maxn];
map<int,int>pw,mp;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	int p=1;
	if(k==1)pw[1]++;//.insert(1);
	else if(k==-1)pw[1]++,pw[-1]++;//.insert(1),pw.insert(-1);
	else while(p<=INF)pw[p]++,p*=k;
	
	for(int i=1;i<=n;i++)cin>>sum[i],sum[i]+=sum[i-1];
	
	int ans=0;mp[0]++;
	for(int i=1;i<=n;i++){
		for(auto w:pw)if(mp.find(sum[i]-w.F)!=mp.end())ans+=mp[sum[i]-w.F];
		mp[sum[i]]++;
	}

	cout<<ans<<endl;
}