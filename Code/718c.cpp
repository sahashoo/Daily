#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MOD=1e9+7;
const int MAXN=1e5+7;

struct matrix
{
	int val[2][2];
	int n;
	matrix(int _n,int x=0)
	{
		n=_n;
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(i!=j)
					val[i][j]=0;
				else
					val[i][j]=x;
	}
	matrix()
	{
		n=2;
	}
	int* operator[](int x)
	{
		return val[x];
	}
	matrix operator*(matrix b)
	{
		matrix ret(n,0);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{
					ret[i][k]+=(val[i][j]*b[j][k])%MOD;
					ret[i][k]%=MOD;
				}
		return ret;
	}
	matrix operator+(matrix b)
	{
		matrix ret(n,0);
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				ret[i][j]=(val[i][j]+b[i][j])%MOD;
		return ret;
	}
};

	matrix operator^(matrix a,int b)
	{
		matrix ret(a.n,1);
		while(b)
		{
			if(b%2)
				ret=ret*a;
			a=a*a;
			b/=2;
		}
		return ret;
	}

struct node
{
	matrix lzy;
	matrix sum;
	node()
	{
		lzy[0][0]=lzy[1][1]=1;
		lzy[0][1]=lzy[1][0]=0;
		sum[0][0]=sum[0][1]=sum[1][0]=sum[1][1]=0;
	}
};

int arr[MAXN],n;
matrix null_matrix(2,1);
node seg[4*MAXN],null_node;

inline node merge(node a,node b)
{
	node c;
	c.sum=a.sum+b.sum;
	return c;
}

void build(int v=1,int l=0,int r=n)
{
	if(r-l<2)
	{
		seg[v].sum[0][0]=seg[v].sum[0][1]=seg[v].sum[1][0]=1;
		seg[v].sum=seg[v].sum^(arr[l]-1);
		return;
	}
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	build(lc,l,mid);
	build(rc,mid,r);
	seg[v]=merge(seg[lc],seg[rc]);
}

void push_down(int v,const matrix &a)
{
	seg[v].sum=seg[v].sum*a;
	seg[v].lzy=seg[v].lzy*a;
}

void shift(int l,int r,int v)
{
	int lc=v*2,rc=v*2+1;
	if(r-l>=2)
	{
		push_down(lc,seg[v].lzy);
		push_down(rc,seg[v].lzy);
	}
	seg[v].lzy=null_matrix;
}

void update(int s,int e,const matrix &a,int l=0,int r=n,int v=1)
{
	if(s<=l&&r<=e)
	{
		push_down(v,a);
		return;
	}
	if(e<=l||r<=s)
		return;
	shift(l,r,v);
	int mid=(l+r)/2,lc=v*2,rc=lc+1;
	update(s,e,a,l,mid,lc);
	update(s,e,a,mid,r,rc);
	seg[v]=merge(seg[lc],seg[rc]);
}

node get(int s, int e,int l=0,int r=n,int v=1)
{
	if(s<=l&&r<=e)
		return seg[v];
	if(e<=l||r<=s)
		return null_node;
	shift(l,r,v);
	int mid=(l+r)/2,lc=v*2,rc=v*2+1;
	return merge(
					get(s,e,l,mid,lc),
					get(s,e,mid,r,rc)
				);
}

int32_t main()
{
	int q;
	cin>>n>>q;
	for(int i=0;i<n;i++)
		cin>>arr[i];
	build();
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int l,r,x;
			cin>>l>>r>>x;
			l--;
			matrix a(2,0);
			a[0][0]=a[0][1]=a[1][0] = 1;
			a=a^x;
			update(l,r,a);
		}
		else
		{
			int l,r;
			cin>>l>>r;
			l--;
			cout<<get(l,r).sum[0][0]<<endl;
		}
	}
}