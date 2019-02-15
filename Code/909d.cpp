///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int INF=1e9+7535;
const int MAXN=1e5+7;
set<pair<int,pair<int,char> > >st;
vector<pair<int,char> >vec,cp;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	char c='0';
	for(int i=0;i<s.size();i++){
		if(s[i]!=c)vec.push_back({0,s[i]}),c=s[i];
		if(s[i]==c)vec.back().F++;
	}
	int ans=0;
	while(vec.size()>1){
		int mn=INF;
		for(int i=0;i<vec.size();i++){
			if(i==0||i==vec.size()-1){
				if(mn>vec[i].F)
					mn=vec[i].F;
			}
			else if(mn>(vec[i].F+1)/2)
				mn=(vec[i].F+1)/2;
		}
		cp.clear();
		for(int i=0;i<vec.size();i++){
			pair<int,char>tmp;
			if(i==0||i==vec.size()-1)
				tmp={vec[i].F-mn,vec[i].S};
			else tmp={vec[i].F-mn*2,vec[i].S};
			if(tmp.F>0){
				if(cp.size()&&cp[cp.size()-1].S==tmp.S)
					cp[cp.size()-1].F+=tmp.F;
				else
					cp.push_back(tmp);
			}
		}
		vec=cp;
		ans+=mn;
	}
	cout<<ans;
}
