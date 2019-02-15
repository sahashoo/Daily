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
int a[maxn];
map<int,int>mp;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0,x;i<n;i++)cin>>x,a[x]++;
	for(int i=1;i<101;i++){
		// cout<<a[i]<<" ";
		for(int j=i+1;j<101;j++){
			if(a[i]==a[j]&&a[i]!=0&&a[i]+a[j]==n)
				return cout<<"YES\n"<<i<<" "<<j,0;
		}
	}
	cout<<"NO";
}
