///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int maxn=2e5+7;
int n,m,p[maxn],a[maxn],b[maxn];
set<pair<int,int> >s[5];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);		
	cin>>n;
	for(int i=0;i<n;i++)cin>>p[i];
	for(int i=0;i<n;i++){
		cin>>a[i];
		s[a[i]].insert({p[i],i});
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		s[b[i]].insert({p[i],i}); 
	}
	cin>>m;
	while(m--){
		int c;cin>>c;
		if(!s[c].size()){cout<<-1<<" ";continue;}
		pair<int,int>res=*s[c].begin();
		cout<<res.F<<' ';
		s[b[res.S]].erase(res);
		s[a[res.S]].erase(res);
	}
}
