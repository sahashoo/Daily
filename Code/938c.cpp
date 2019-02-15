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
const int MAXN=1e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;

int Sqr(int x){
	int temp=sqrt(x);
	for(int i=-2;i<=2;i++)
		if(temp+i>=0&&(temp+i)*(temp+i)==x)
			return temp;
    return -1;
}

void solve(){
    int x;cin>>x;
	for(int n=1;n==1||n*n-(n/2)*(n/2)<=x;n++){
        int temp=n*n-x;
        if(temp<0)continue;
        int sq=Sqr(temp);
        if(sq<=0)continue;
        int m=n/sq;
		temp=n*n-(n/m)*(n/m);
        if(m>0&&temp==x){
			cout<<n<<" "<<m<<'\n';
			return;
		}
    }
	cout<<"-1\n";
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int q;cin>>q;
	while(q--)solve();
}
