#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+7;
const int K=17;
int mx[18][N][6],t[N];

inline int MAX(int i,int l,int r)
{
	int id=t[r-l];
	if(l==r)
		return 0;
	return max(mx[id][l][i],mx[id][r-(1<<id)][i]);
}

inline int val(int l,int r)
{
	int ret=0;
	for(int i=0;i<5;i++)
		ret+=MAX(i,l,r);
	return ret;
}

int32_t main()
{
	for(int i=2;i<N;i++)
		t[i]=t[i/2]+1;
	
	int n,m,k;
	cin>>n>>m>>k;
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>mx[0][i][j];
		
	for(int b=0;b<m;b++)
		for(int i=1;i<K;i++)
			for(int j=0;j<n;j++)
			{
				if(j+(1<<(i-1))>=n)
					mx[i][j][b]=mx[i-1][j][b];
				else
					mx[i][j][b]=max( mx[i-1][j][b], mx[i-1][ j+(1<<(i-1)) ][b]);
			}
	
	int l=0,r=0,p=0;
	for(int i=0;i<n;i++)
	{
		while(p<=n&&val(i,p)<=k)
			p++;
		if(p-1-i > r-l)
		{
			l=i;
			r=p-1;
		}
	}
	
	for(int i=0;i<m;i++)
		cout<<MAX(i,l,r)<<" ";
	
}