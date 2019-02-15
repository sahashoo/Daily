#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;
const int SQ=320;
int spl[MAXN],shr[MAXN][SQ],ptr[MAXN],sum[MAXN],a[MAXN];
vector<int>hvy,st[MAXN],whr[MAXN];
bool is_hvy[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	int n,m,q;cin>>n>>m>>q;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=m;i++){
		int ln;cin>>ln;
		if(ln>SQ){
			hvy.push_back(i);
			is_hvy[i]=true;
			ptr[i]=hvy.size()-1;
		}
		for(int j=0;j<ln;j++){
			int id;cin>>id;
			st[i].push_back(id);
			whr[id].push_back(i);
			sum[i]+=a[id];
		}
	}
	for(int i=1;i<=n;i++)
		for(int j:whr[i])
			for(int k:whr[i])
				if(k!=j&&is_hvy[k]==true)
					shr[j][ptr[k]]++;
	while(q--){
		char type;cin>>type;
		if(type=='+'){
			int k,x;cin>>k>>x;
			if(is_hvy[k]==false){
				for(int i:st[k])a[i]+=x;
				for(int i=0;i<hvy.size();i++)
					sum[hvy[i]]+=x*shr[k][i];
			}
			else spl[k]+=x;
		}
		else{
			int k,ans=0;cin>>k;
			if(is_hvy[k]==true){
				ans=sum[k]+spl[k]*st[k].size();
				for(int i=0;i<hvy.size();i++)
					ans+=spl[hvy[i]]*shr[k][i];
			}
			else{
				for(int i:st[k])ans+=a[i];
				for(int i=0;i<hvy.size();i++)
					ans+=spl[hvy[i]]*shr[k][i];
			}
			cout<<ans<<'\n';
		}
	}
}