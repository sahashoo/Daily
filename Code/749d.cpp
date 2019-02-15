///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e5+7;
int n,q,flg[maxn];
vector<int>v[maxn],prsn,prsn2;
bool mrk[maxn];
vector<pair<int,int> >ans;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int a,b;cin>>a>>b;
		v[a-1].push_back(b);
		prsn2.push_back(a-1);
	}
	for(int i=prsn2.size()-1;i>=0;i--){
		if(!mrk[prsn2[i]])prsn.push_back(prsn2[i]);
		mrk[prsn2[i]]=true;
	}
	reverse(prsn.begin(),prsn.end());
	cin>>q;
	for(int i=0;i<maxn;i++)flg[i]=maxn*maxn;
	for(int i=0;i<q;i++){
		int k;cin>>k;
		for(int j=0;j<k;j++){
			int a;cin>>a;
			flg[a-1]=i;
		}
		int ind=(int)prsn.size()-1;//cout<<987654321;
		while(ind>0&&flg[prsn[ind]]==i)ind--;
		if(flg[prsn[ind]]==i){ans.push_back({0,0});continue;}
		int id=ind-1;
		while(id>0&&flg[prsn[id]]==i)id--;
		if(ind==0||flg[prsn[id]]==i){ans.push_back({prsn[ind]+1,v[prsn[ind]][0]});continue;}
		int it=upper_bound(v[prsn[ind]].begin(),v[prsn[ind]].end(),v[prsn[id]][v[prsn[id]].size()-1])-v[prsn[ind]].begin();
		ans.push_back({prsn[ind]+1,v[prsn[ind]][it]});
	}
	for(int i=0;i<ans.size();i++)cout<<ans[i].first<<" "<<ans[i].second<<endl;
}

