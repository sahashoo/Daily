///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,m,flg[maxn],a[maxn];
bool mrk[maxn];
set<int>s;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<m;i++)cin>>a[i];
	for(int i=1;i<=n;i++)s.insert(i);
	for(int i=0;i<m-1;i++){
		int u=((a[i+1]-a[i]+n)%n==0?n:(a[i+1]-a[i]+n)%n);
		if(flg[a[i]]!=0&&flg[a[i]]!=u)return cout<<-1,0;
		else s.erase(u),flg[a[i]]=u;
	}
	for(int i=1;i<=n;i++){
		if(mrk[flg[i]])return cout<<-1,0;
		if(!flg[i])flg[i]=*s.begin(),s.erase(s.begin());
		mrk[flg[i]]=true;
	}
	for(int i=1;i<=n;i++)cout<<flg[i]<<" ";
}
