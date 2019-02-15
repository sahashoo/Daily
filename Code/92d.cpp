#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
set<int>st;
unordered_map<int,vector<int> >mp;
int ans[MAXN],a[MAXN];

int32_t main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a[i]=x;
		mp[x].push_back(i);
		st.insert(x);
	}
	int mx=-1;
	while(st.size()){
		int x=*st.begin();
		st.erase(x);
		for(int i:mp[x]){
			ans[i]=(i<mx?mx-i-1:-1);
			mx=max(i,mx);
		}
	}
	for(int i=0;i<n;i++)cout<<ans[i]<<" ";
}