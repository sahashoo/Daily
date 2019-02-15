///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e7+5,INF=1e18+7;
int n,k,q,a[maxn];
bool mrk[maxn];
vector<int>ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	for(int i=0;i<n;i++)cin>>a[i],mrk[a[i]]=true;
	cin>>q;
    while(q--){
		int x,res=INF;cin>>x;
		for(int i=0;i<n;i++){
			int j=k-1,sum=x-a[i];
			while(j>=0&&sum>=0){
				if(sum==0)res=min(res,k-j);
				else{
					for(int o=1;o<=j;o++){
						int d=sum/o;
						if(sum==d*o&&d<maxn&&mrk[d])res=min(res,k-j+o);
					}
				}
				j--;sum-=a[i];
			}
		}
		if(res==INF)ans.push_back(-1);
		else ans.push_back(res);
    }
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<endl;
}
