#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
int n,mx;
vector<int>v;
map<pair<int,int>,pair<int,int> >mp;

void check(int a,int b,int c,int i){
	if(mp.count({a,b})==0)return ;
	pair<int,int>tmp=mp[{a,b}];
	int cur=min({a,b,tmp.F+c});
	if(mx<cur)mx=cur,v.clear(),v.push_back(i),v.push_back(tmp.S);
}

int32_t main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int a[5];cin>>a[0]>>a[1]>>a[2];
		sort(a,a+3);
		if(mx<a[0])mx=a[0],v.clear(),v.push_back(i);
		check(a[0],a[1],a[2],i);
		check(a[0],a[2],a[1],i);
		check(a[1],a[2],a[0],i);
		mp[{a[0],a[1]}]=max(mp[{a[0],a[1]}],{a[2],i});
		mp[{a[1],a[2]}]=max(mp[{a[1],a[2]}],{a[0],i});
		mp[{a[0],a[2]}]=max(mp[{a[0],a[2]}],{a[1],i});
	}
	cout<<v.size()<<endl;
	for(auto x:v)cout<<x+1<<" ";
}