///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
using namespace std;
void null(){return ;}
const int maxn=3e5+7,INF=3e18+9237,mod=1e9+7;
int a[maxn];
bool opn[maxn],cls[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	cls[0]=opn[n+1]=true;
	for(int i=1;i<=n;i++){
		for(int j=i;j>0;j--){
			if(a[i]%2&&a[j]%2&&(i-j+1)%2&&cls[j-1])opn[i]=true;
			if(a[i]%2&&a[j]%2&&(i-j+1)%2&&opn[j-1])cls[i]=true;
		}
	}
	if(opn[n]%2)cout<<"Yes";
	else cout<<"No";
}
