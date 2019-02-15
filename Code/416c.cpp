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
pair<int,int>r[maxn];
pair<int,pair<int,int> >a[maxn];
bool mrk[maxn];
vector<pair<int,int> >ans;

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k;cin>>n;
	for(int i=0;i<n;i++)cin>>a[i].F>>a[i].S.F,a[i].S.S=i;
	cin>>k;
	for(int i=0;i<k;i++)cin>>r[i].F,r[i].S=i;
	sort(r,r+k);
	sort(a,a+n);
	int sum=0,cnt=0;
	for(int i=0;i<k;i++){
		int mx=0,pl=-1;
		for(int j=0;j<n;j++){
			if(mrk[j]==false&&a[j].F<=r[i].F){
				if(a[j].S.F>=mx){
					if(pl!=-1)mrk[pl]=false;
					pl=j;
					mx=a[j].S.F;
					mrk[j]=true;
				}
			}
		}
		if(pl!=-1){
			cnt++;
			sum+=a[pl].S.F;
			ans.pb({a[pl].S.S+1,r[i].S+1});
		}
	}
	cout<<cnt<<" "<<sum<<'\n';
	for(auto x:ans)cout<<x.F<<" "<<x.S<<'\n';
}
