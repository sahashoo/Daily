#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,m,a[maxn],res,sum,ans;
vector<int>g[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=0;i<m-1;i++){
		if(a[i]!=a[i+1]){
			g[a[i]].push_back(a[i+1]);
			g[a[i+1]].push_back(a[i]);
			sum+=abs(a[i]-a[i+1]);
		}
	}
	ans=sum;
	for(int i=1;i<=n;i++){
		if(g[i].size()){
			sort(g[i].begin(),g[i].end());
			int cur=sum;
			for(int j=0;j<g[i].size();j++){
				cur-=abs(g[i][j]-i);
				cur+=abs(g[i][j]-g[i][0]);
			}
			ans=min(ans,cur);
			for(int j=1;j<g[i].size();j++){
				int dec=g[i].size()-j;
				int inc = j;
				cur+=(j+j-g[i].size())*(g[i][j]-g[i][j-1]);
				ans=min(ans,cur);
			}
		}
	}
	cout<<ans;
}
