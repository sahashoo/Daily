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
int a[maxn],x[maxn];
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m,k;cin>>n>>k>>m;
	for(int i=0;i<n;i++)cin>>x[i],a[x[i]%m]++;
	
	for(int i=0;i<m;i++){
		if(a[i]>=k){
			// cout<<i<<endl;
			cout<<"Yes\n";
			int cnt=0;
			for(int j=0;j<n;j++){
				if(x[j]%m==i)cout<<x[j]<<" ",cnt++;
				if(cnt==k)return 0;
			}
		}
	}
	cout<<"No";
}
