///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
int n,a[maxn];

int rmq(int h=0,int l=0,int r=n-1){
	if(r<l)return 0;
	int id=l,mn=a[l];
	for(int i=l;i<=r;i++)if(mn>a[i])id=i,mn=a[i];
	return min(r-l+1,rmq(mn,l,id-1)+rmq(mn,id+1,r)+mn-h);
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	cout<<rmq();
}
