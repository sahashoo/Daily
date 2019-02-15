///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
const int lgN=23;
int a[maxn],b[maxn],rmnq[maxn][lgN],rmxq[maxn][lgN],lg[maxn],n,res;

void precomput(){
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++)cin>>b[i];
	
	lg[1]=0;
	for(int i=2;i<maxn;i++)lg[i]=lg[i/2]+1;
    for(int i=0;i<n;i++)rmxq[i][0]=a[i];
    for(int i=0;i<n;i++)rmnq[i][0]=b[i];
	
	for(int j=1;j<lgN;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			rmnq[i][j]=min(rmnq[i][j-1],rmnq[i+(1<<(j-1))][j-1]);
	
	for(int j=1;j<lgN;j++)
		for(int i=0;i+(1<<j)<=n;i++)
			rmxq[i][j]=max(rmxq[i][j-1],rmxq[i+(1<<(j-1))][j-1]);
}

int mn(int l,int r){
    int x=lg[r-l];
    return min(rmnq[l][x],rmnq[r-(1<<x)][x]);
}

int mx(int l,int r){
    int x=lg[r-l];
    return max(rmxq[l][x],rmxq[r-(1<<x)][x]);
}

int lower(int l,int r=n+1){
	int bgn=l;
	while(r-l>1){
		int mid=l+r>>1;
		if(mx(bgn,mid)<=mn(bgn,mid))l=mid;
		else r=mid;
	}
	return l;
}

int upper(int l,int r=n+1){
	int bgn=l;
	while(r-l>1){
		int mid=l+r>>1;
		if(mx(bgn,mid)<mn(bgn,mid))l=mid;
		else r=mid;
	}
	return l;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	precomput();
	for(int i=0;i<n;i++)res+=lower(i)-upper(i);
	cout<<res;
}
