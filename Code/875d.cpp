///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=3e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
bool mrk[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,pos;cin>>n;
	int cnt=0,l=n+1;
	cout<<1<<" ";
	for(int i=1;i<=n;i++){
		cin>>pos;mrk[pos]=true;
		while(mrk[l-1]==true)l--,cnt++;
		cout<<i-cnt+1<<" ";
	}
}
