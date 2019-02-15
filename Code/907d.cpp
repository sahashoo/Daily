///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define pb push_back
using namespace std;
const int MAXN=1e5+7;
vector<int>ans[MAXN],pos[2];
int n,m;

inline int p(int i,int j){return i*m+j+1;}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	int mx=max(n,m),mn=min(n,m);
	if(mx==1)return cout<<"YES\n1\n",0;
	if(mx<=2)return cout<<"NO\n",0;
	if(mx==3){
		if(mn<=2)return cout<<"NO\n",0;
		else return cout<<"YES\n6 1 8\n7 5 3\n2 9 4\n",0;
	}
	cout<<"YES\n";
	if(m<4){
		for(int i=0;i<n;i++)pos[!(i%2)].pb(i);
		for(int i=0;i<n;i++)pos[(i%2)].pb(i);
		if(n==4){
			pos[0].clear();
			pos[0].pb(2);pos[0].pb(0);pos[0].pb(3);pos[0].pb(1);
			pos[1].clear();
			pos[1].pb(1);pos[1].pb(3);pos[1].pb(0);pos[1].pb(2);
		}
		for(int i=0;i<m;i++)
			for(int j=0;j<n;j++)
				ans[i].pb(p(pos[i%2][j],i));
		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++)
				cout<<ans[j][i]<<" ";
			cout<<endl;
		}
		return 0;
	}
	for(int i=0;i<m;i++)pos[!(i%2)].pb(i);
	for(int i=0;i<m;i++)pos[(i%2)].pb(i);
	if(m==4){
		pos[0].clear();
		pos[0].pb(2);pos[0].pb(0);pos[0].pb(3);pos[0].pb(1);
		pos[1].clear();
		pos[1].pb(1);pos[1].pb(3);pos[1].pb(0);pos[1].pb(2);
	}
	// cout<<"HERE 1 "<<endl;
	// cout<<pos[0][0]<<endl;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<p(i,pos[i%2][j])<<" ";//<<endl;
		cout<<endl;
	}
}