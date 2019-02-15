#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;

struct fenwick
{															//do sum query
	int fen[MAXN],n;
	
	void update(int i,int val)
	{
		for(;i<=n;i+=i&(-i))
			fen[i]+=val;
	}
	
	fenwick(int *a,int _n)
	{
		n=_n;
		for(int i=1;i<=n;i++)
			update(i,a[i]);
	}
	
	int check(int x,int sum=0)
	{
		for(;x>0;x-=x&(-x))
			sum+=fen[x];
		return sum;
	}

};

int a[MAXN];
int32_t main()
{
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	fenwick t(a,n);
	
	for(int i=0;i<m;i++)
	{
		int q,val;
		cin>>q>>val;
		t.update(q,val);
	}
	cout<<t.check(n);
}
