///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=3e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i];
	int L=0,R=0,l=0,r=0,cnt=0;
	while(L!=n&&R!=n){
		while(R<n&&cnt<=k)cnt+=(a[R]==0),R++;
		if(a[R-1]==0&&cnt>k)cnt--,R--;
		if(r-l<R-L)r=R,l=L;
		if(a[L]==0)cnt--;
		L++;
	}
	cout<<r-l<<endl;
	for(int i=0;i<n;i++)cout<<(l<=i&&i<r?1:a[i])<<" ";
}
