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
using namespace std;
const int INF=3e18+9237;
const int MAXN=1e6+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,a,b,x,y,p[MAXN];

void make(int l,int r){
	p[l]=r;
	for(int i=l+1;i<=r;i++)
		p[i]=i-1;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>x>>y;
	a=max(x,y),b=min(x,y);
	
	x=0,y=0;
	for(int i=0;i<=n/a;i++){
		int temp=n-i*a;
		if(temp%b==0){
			x=i,y=temp/b;
			break;
		}
	}
	
	if(y==0&&x==0)return cout<<-1,0;
	
	int id=1;
	for(int i=0;i<x;i++)
		make(id,id+a-1),id+=a;
	for(int i=0;i<y;i++)
		make(id,id+b-1),id+=b;
	
	for(int i=1;i<=n;i++)
		cout<<p[i]<<" ";
}
