#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int N=1e3+7;

struct pascal
{
	int c[N][N];
	void prep()
	{
		for(int i=0;i<N;i++)
			for(int j=0;j<N;j++)
			{
				if(i<j)
					c[i][j]=0;
				else if(i==j||j==0)
					c[i][j]=1;
				else
					c[i][j]=(c[i][j-1]+c[i-1][j-1])%mod;
			}
	}
	int C(int n,int k)
	{
		return c[n][k];
	}
};

struct ferma
{
	int f[MAXN],fi[MAXN];
	int pw(int a,int b)
	{
		int ret=1;
		while(b)
		{
			if(b&1)ret=(1ll*a*ret)%mod;
			a=(1ll*a*a)%mod;b/=2;
		}
		return ret;
	}
	void prep()
	{
		f[0]=1;
		for(int i=1;i<N;i++)
			f[i]=(f[i-1]*i)%mod;
		
		fi[N-1]=pw( f[N-1] , mod-2 );
		for(int i=N-1;i>0;i--)
			fi[i-1]=(fi[i]*i)%mod;
	}
	int C(int n,int k)
	{
		if(k<0||k>n)
			return 0;
		if(k==0)
			return 1;
		return (f[n]* ((fi[k]*fi[n-k])%mod) )%mod;
	}
};

struct lucas
{	
	int f[MAXN],fi[MAXN];
	int pw(int a,int b)
	{
		int ret=1;
		while(b)
		{
			if(b&1)ret=(1ll*a*ret)%mod;
			a=(1ll*a*a)%mod;b/=2;
		}
		return ret;
	}
	void prep()
	{
		f[0]=1;
		for(int i=1;i<N;i++)
			f[i]=(f[i-1]*i)%mod;
		
		fi[N-1]=pw( f[N-1] , mod-2 );
		for(int i=N-1;i>0;i--)
			fi[i-1]=(fi[i]*i)%mod;
	}
	int C(int n,int k)
	{
		if(k<0||k>n)
			return 0;
		if(k==0)
			return 1;
		if(n>mod)
			return ( C(n%mod,k%mod) * C(n/mod,k/mod) )%mod;
		
		return (f[n]* ((fi[k]*fi[n-k])%mod) )%mod;
	}
};

int32_t main()
{

}
