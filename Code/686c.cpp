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
int lgn,lgm,ans;
vector<int>a,b;

int log7(int a){
	return (a?log7(a/7)+1:0);
}

void make(vector<int>&v,int a,int len){
	v.clear();
	while(a){
		v.pb(a%7);
		a/=7;
	}
	while(sz(v)<len)v.pb(0);
}

bool check(){
	set<int>st;
	for(int x:a){
		if(st.count(x))return false;
		else st.insert(x);
	}
	for(int x:b){
		if(st.count(x))return false;
		else st.insert(x);
	}
	return true;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,m;cin>>n>>m;
	lgn=(n==1?1:log7(n-1));
	lgm=(m==1?1:log7(m-1));
	if(lgm+lgn>7){
		return cout<<0,0;
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			make(a,i,lgn);
			make(b,j,lgm);
			ans+=check();
		}
	}
	cout<<ans<<endl;
}
