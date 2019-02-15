///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
#define bug(i) cout<<"bugbug"<<i<<endl
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=2e5+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int n,a[maxn],cnt[maxn];
bool usd[maxn];
queue<int>Q;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++)cin>>a[i],cnt[a[i]]++;
	for(int i=1;i<=n;i++)if(cnt[i]==0)Q.push(i);
	int cng=Q.size();
	for(int i=0;i<n;i++){
		if(cnt[a[i]]>1){
			if(usd[a[i]])cnt[a[i]]--,a[i]=Q.front(),Q.pop();
			else{
				if(Q.front()<a[i])cnt[a[i]]--,a[i]=Q.front(),Q.pop();
				else usd[a[i]]=true;
			}
		}
	}
	cout<<cng<<"\n";
	for(int i=0;i<n;i++)cout<<a[i]<<" ";
}
