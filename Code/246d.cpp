///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int col[100007];
set<int>st[100007];
bool mrk[100007];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>col[i],mrk[col[i]]=true;;
	for(int i=0,u,v;i<m;i++){
		cin>>u>>v;
		if(col[u]==col[v])continue;
		st[col[v]].insert(col[u]);
		st[col[u]].insert(col[v]);
	}
	int mx=-1,ind=0;
	// cout<<mx<<endl;
	for(int c=1;c<100001;c++)
		if(mrk[c]==true&&((int)st[c].size()>mx))
			mx=st[c].size(),ind=c;//,cout<<c<<endl;;
	cout<<ind;
}