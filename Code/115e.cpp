#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int MAXN=2e5+7;
int a[MAXN],w[MAXN],dp[MAXN],seg[4*MAXN],lazy[4*MAXN],n;
vector<pair<int,pair<int,int> > >vec;

void update(int s,int e,int x,int v=1,int l=0,int r=n+1)
{
	// if(s>=r||l<=e)
		// return ;
	if(s<=l&&r<=e)
	{
		lazy[v]+=x;
		seg[v]+=x;
		return ;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	if(s<mid)
		update(s,e,x,lc,l,mid);
	if(mid<e)
		update(s,e,x,rc,mid,r);
	
	seg[v]=max(seg[lc],seg[rc])+lazy[v];
}

int query(int s,int e,int v=1,int l=0,int r=n+1)
{
	// if(s>=r||l<=e)
		// return -1e15;
	if(s<=l&&r<=e)
        return seg[v];
	
	int mid=(l+r)/2,lc=v*2,rc=v*2+1,a=0,b=0;
	if(s<mid)
        a=query(s,e,lc,l,mid);
	if(mid<e)
		b=query(s,e,rc,mid,r);
	
	return max(a,b)+lazy[v];
}


int32_t main()
{
    int m;
    cin>>n>>m;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
	{
		int l,r;
        cin>>l>>r>>w[i];
        vec.push_back({r,{l,i}});
    }
    sort(vec.begin(),vec.end());

    int j=0;
    for(int i=1;i<=n;i++)
	{
        update(0,i,-a[i-1]);
        while(vec[j].F==i)
		{
            update(0,vec[j].S.F,w[vec[j].S.S]);
            j++;
        }
        dp[i]=query(0,i+1);
        if(i<n)
		{
            update(i+1,i+2,dp[i]);
        }
    }

    cout<<dp[n]<<endl;
}