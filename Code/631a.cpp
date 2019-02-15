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
int a[maxn],b[maxn],aor[maxn],bor[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];
	for(int i=1;i<=n;i++)aor[i]=aor[i-1]|a[i],bor[i]=bor[i-1]|b[i];
	int mx=0;
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			mx=max(mx,(aor[r]|aor[l-1])+(bor[r]|bor[l-1]));
		}
	}
	cout<<mx;;
}
