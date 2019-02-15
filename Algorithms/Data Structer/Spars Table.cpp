///spars[i][j]=g(x),where x is Function(a,b) of the interval that start from i ans have length of 2^j  
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+7,lgN=16;// log 2 N=17
int n,a[N],tr[N][lgN];

int Function(int a,int b){
	//it could be any associative f
	return a+b;
}

void build()
{
	for(int j=1;j<=logN;j++)
	{
		for(int i=0;i<=n-(1<<j);i++)
		{
			tr[i][j]=tr[i][j-1]+tr[i+(1<<(j-1))][j-1];
		}
	}
}

int act(int l,int r)
{
	int res=0;
	for(int i=logN;i>=0;i--)
		if(l+(1<<i)-1<=r)
		{
			res+=tr[l][i];
			l+=1<<i;
		}
	return res;
}

int32_t main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		cin>>a[i],tr[i][0]=a[i];
	build();
	int l,r;cin>>l>>r;
	cout<<act(l-1,r-1);
}