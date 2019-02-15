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
const int maxn=2e6+7,N=1e6,INF=3e18+9237,mod=1e9+7;
bool mrk[maxn];
int a[101],b[101];

void solve(int ind){
	memset(mrk,false,sizeof(mrk));
	memset(a,0,sizeof(a));
	memset(b,0,sizeof(b));
	
	int n;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i];
	
	sort(a,a+n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			mrk[a[j]-a[i]]=true;
		}
	}
	
	int k=1;
	for(int i=0;i<n;i++){
		if(k>N)return cout<<"NO\n",null();
		b[i]=k;
		bool chck=true;
		while(chck&&k<=N){
			chck=false;k++;
			for(int j=0;j<=i;j++){
				if(mrk[k-b[j]]){
					chck=true;
					break;
				}
			}
        }
	}
	
	cout<<"YES\n";
	for(int i=0;i<n;i++)cout<<b[i]<<' ';cout<<'\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int t;cin>>t;
	for(int i=0;i<t;i++)solve(i);
}
