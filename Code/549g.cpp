///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,a[maxn],b[maxn];

bool SORT(int l,int r){
	if(l==r)return true;
	else{
		int mid=(l+r)/2;
		if(!SORT(l,mid)||!SORT(mid+1,r))return false;
		int sub=0,i=l,j=mid+1,cnt=l;
		while(i<=mid||j<=r){
			if(i<=mid&&(j>r||a[j]+mid+1-i>a[i]-sub))b[cnt++]=a[i]-sub,i++;
			else b[cnt++]=a[j]+mid+1-i,sub++,j++;
		}
		for(int i=l;i<=r;i++){
			a[i]=b[i];
			if(i>l&&a[i-1]>a[i])return false;
		}
		return true;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	if(SORT(0,n-1))for(int i=0;i<n;i++)cout<<a[i]<<" ";
	else cout<<":(";
}