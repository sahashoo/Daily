///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
// #define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
// const int INF=3e18+9237;
const int maxn=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[maxn];
map<int,int>b,cnt;
vector<int>cng;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	for(int i=0;i<n;i++)cin>>a[i],b[a[i]]++;
	int apl=n/m;
	for(int i=0;i<n;i++){
		cnt[a[i]]++;
		if(cnt[a[i]]>apl||a[i]>m)cng.push_back(i);
	}
	// for(auto x:cng)cout<<x<<" ";cout<<endl;
	int p=0,res=0;
	for(int i=1;i<=m;i++){
		while(b[i]<apl){
			res++;
			b[i]++;
			a[cng[p++]]=i;
		}
	}
	cout<<apl<<" "<<res<<'\n';
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
