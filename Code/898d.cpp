///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e6+1;
int res,a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>m>>k;
	for(int i=0,x;i<n;i++)cin>>x,a[x]++;
	int sum=0,ind=m-1;
	for(int i=0;i<m;i++)sum+=a[i];
	for(int l=1;l<=MAXN-m;l++){
		ind=l+m-1;
		sum=sum-a[l-1]+a[ind];
		while(sum>=k&&ind>=l){
			int dif=sum-k+1;
			if(a[ind]>=dif)
				res+=dif,a[ind]-=dif,sum-=dif;
			else
				res+=a[ind],sum-=a[ind],a[ind]=0,ind--;
		}
	}
	cout<<res;
}
