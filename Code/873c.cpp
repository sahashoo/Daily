///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,m,k,a[102][102],sum[102],res,mx;
vector<pair<int,int> >tmp;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
		
	for(int j=1;j<=m;j++){
		int tmp=0,ind=0;
		for(int i=n;i>0;i--){
			sum[i]=sum[i+1]+a[i][j];
			if(sum[i]-sum[i+k]>=tmp)
				ind=i,tmp=sum[i]-sum[i+k];
		}
		mx+=tmp;
		res+=sum[1]-sum[ind];
	}
	cout<<mx<<" "<<res;
}
