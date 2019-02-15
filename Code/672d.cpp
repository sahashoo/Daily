///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+7,INF=1e9;
int n,k,a[maxn];

bool RICH(int x){
	int cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		if(a[i]>x)cnt+=a[i]-x;
		else cnt2+=x-a[i];
	}
	return cnt<=k&&cnt2>=cnt;
}

bool POOR(int x){
	int cnt=0,cnt2=0;
	for(int i=0;i<n;i++){
		if(a[i]>x)cnt+=a[i]-x;
		else cnt2+=x-a[i];
	}
	return cnt2<=k&&cnt>=cnt2;
}

int MAX(){
	int l=0,r=INF,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(RICH(mid))res=mid,r=mid-1;
		else l=mid+1;
	}
	return res;
}

int MIN(){
	int l=0,r=INF,res=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(POOR(mid))res=mid,l=mid+1;
		else r=mid-1;
	}
	return res;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<MAX()-MIN();

}