#include<bits/stdc++.h>
#define int long long
#define ld long double
#define sz(x) (int)(x).size()
#define pb push_back
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define all(x) x.begin(), x.end()
#define For(i,n)  for(int i=0;i<n;i++)
#define Forr(i,n) for(int i=n-1;i>=0;i--)
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define FORR(i,a,b) for(int i=a;i>=b;i--)
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,t1=0,t2=0,a;
char c;


int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>t1;
	for(int i=0;i<n;i++){
		cin>>c>>a;
		if(c=='+')t1+=a;
		else{
			if(t1>=a)t1-=a;
			else t2++;
		}
	}
	cout<<t1<<" "<<t2;
}
