///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define ld long double
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=1e5+7,INF=3e18+9237,mod=1e9+7;
string s[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>s[i];
	int mx=0;
	for(int i=0;i<7;i++){
		int tmp=0;
		for(int j=0;j<n;j++)
			if(s[j][i]=='1')tmp++;
		mx=max(tmp,mx);
	}
	cout<<mx;
}
