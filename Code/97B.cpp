#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+9;
pair<int,int>p[MAXN];
set<pair<int,int> >a;

void f(int l,int r)
{
	if(r-l<2)
		return ;
	int m=(l+r)/2;
	for(int i=l;i<r;i++)
		a.insert({p[m].first,p[i].second});
	f(l,m);
	f(m,r);
}

int32_t main()
{
	int n;cin>>n;
	for(int i=0;i<n;i++)
		cin>>p[i].F>>p[i].S,a.insert(p[i]);
	sort(p,p+n);
	f(0,n);
	cout<<a.size()<<"\n";
	for(auto i:a)
		cout<<i.F<<" "<<i.S<<"\n";
}