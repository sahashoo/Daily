#include<bits/stdc++.h>
#define int unsigned long long
using namespace std;
int mod;

struct matrix{
	int a[2][2],n;
	matrix(int nn=0){
		n=nn;
		memset(a,0,sizeof a );
	}
};
matrix operator *(matrix a,matrix b){
	#define F(i) for(int i=0;i<=1;i++)
	matrix ret;
	F(i)F(j)F(k)
		ret.a[i][j]=(ret.a[i][j]+(a.a[i][k]*b.a[k][j])%mod)%mod;
	return ret;
}
matrix mpw(matrix a,int x){
	matrix ret;
	ret.a[1][1]=ret.a[0][0]=1;
	if(x==0)return ret;
	ret=mpw(a,x/2);
	return x&1?ret*ret*a:ret*ret;
}

int pw(int a,int b){
	int ret=1;
	if(b==0)return ret;
	ret=pw(a,b/2);
	return (((ret*ret)%mod)*(b%2?a:1))%mod;
}

int32_t main(){
	int n,l,k,mr=0;
	cin>>n>>k>>l>>mod;
	matrix m;
	m.a[0][0]=m.a[1][0]=m.a[0][1]=1;
	m=mpw(m,n+1);
	int a1=m.a[0][0],a2=1,temp=pw(2,n);
	for(int i=0;i<l;i++){
		if(k&(1ll<<i)){
			mr+=(1ll<<i);
			a2=(a2*((temp-a1+mod)%mod))%mod;
		}
		else a2=(a2*a1)%mod;
	}
	// cout<<k<<" "<<mr<<endl;
	if(k-mr)cout<<0;
	else cout<<a2%mod;
}