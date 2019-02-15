#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
const int maxn=1e5+7;
int a[maxn];
set<int>s;

int32_t main(){
	int n,l,x,y;cin>>n>>l>>x>>y;
	for(int i=0;i<n;i++)cin>>a[i],s.insert(a[i]);
	bool cx=false,cy=false;
	for(int i=0;i<n;i++){
		if(s.count(a[i]+x))cx=true;
		if(s.count(a[i]+y))cy=true;
	}
	if(cx&&cy)return cout<<0,0;
	if((cx&&(!cy))||((!cx)&&cy))return cout<<1<<endl<<(cx?y:x),0;
	for(int i=0;i<n;i++){
		if(s.count(a[i]+y-x)&&a[i]-x>=0)return cout<<1<<endl<<a[i]-x,0;
		if(s.count(a[i]-y+x)&&a[i]+x<=l)return cout<<1<<endl<<a[i]+x,0;
		if(s.count(a[i]-y-x)&&a[i]-x-y>=0)return cout<<1<<endl<<a[i]-x,0;
		if(s.count(a[i]+y+x)&&a[i]+x+l<=l)return cout<<1<<endl<<a[i]+y+x,0;
	}
	cout<<2<<endl<<x<<" "<<y;
}