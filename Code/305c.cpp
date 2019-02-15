///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int a[maxn],n,cnt,mx;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[n-i-1];
	while(n>0){
		int i=n-1;
		while(i>0&&a[n-1]==a[i-1])i--;
		int k=n-i;
		if(k%2)cnt++,n--,mx=max(mx,a[n]);
		k/=2;n-=k;
		for(int i=0;i<k;i++)a[n-i-1]++;
	}
	cout<<mx-cnt+1;
}
