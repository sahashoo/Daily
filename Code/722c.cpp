#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+100;
int n,a[maxn],b[maxn],sum[maxn],num[maxn],ans[maxn],cnt=1;
bool mrk[maxn];
vector<int>V[maxn];

int add(int pos){
	mrk[pos]=true;
	if(mrk[pos+1]==false&&(pos==0||mrk[pos-1]==false)){
		num[pos]=cnt;cnt++;
		sum[num[pos]]=a[pos];
		V[num[pos]].push_back(pos);
		return sum[num[pos]];
	}
	if(mrk[pos+1]==false&&mrk[pos-1]==true){
		num[pos]=num[pos-1];
		sum[num[pos]]+=a[pos];
		V[num[pos]].push_back(pos);
		return sum[num[pos]];
	}
	if(mrk[pos+1]==true&&(pos==0||mrk[pos-1]==false)){
		num[pos]=num[pos+1];
		sum[num[pos]]+=a[pos];
		V[num[pos]].push_back(pos);
		return sum[num[pos]];
	}
	int u=num[pos-1],v=num[pos+1];
	if(V[u].size()<V[v].size())swap(u,v);
	for(auto X:V[v])V[u].push_back(X),num[X]=u;
	V[u].push_back(pos);
	sum[u]+=sum[v]+a[pos];
	return sum[u];
}

int32_t main(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	for(int i=n-1;i>=0;i--)ans[i]=max(ans[i+1],add(b[i]-1));
	for(int i=1;i<=n;i++)cout<<ans[i]<<endl;
	return 0;
}