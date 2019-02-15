#include<bits/stdc++.h>
#define int long long
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define sz(x) (int)(x).size()
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=2e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int a[MAXN],n;
string s;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	For(i,n)cin>>a[i];
	cin>>s;

	int p=n+1;
	Forr(i,n-1){
		if(s[i]=='0')p=i+1;
		if(a[i]>p)return cout<<"NO",0;
	}
	
	cout<<"YES";
	
}
