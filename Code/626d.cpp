///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define ld long double
using namespace std;
const int N=5007;
int n,a[N];
ld dist[N],mdist[N],res;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			dist[abs(a[i]-a[j])]+=(ld)2/(n*(n-1));
		}
	}
	for(int i=N;i>=0;i--)mdist[i]=(ld)dist[i]+mdist[i+1];
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(i+j+1<N)res+=(ld)dist[i]*dist[j]*mdist[i+j+1];
		}
	}
	cout<<fixed<<setprecision(12)<<res;
}
