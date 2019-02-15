///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define F first
#define S second
using namespace std;
const int MAXN=1e5+7;
bool mrk[MAXN];
vector<pair<int,pair<int,int> > >seg;
vector<pair<int,pair<int,int> > >vec;

inline bool tadakhol(int ind){
	bool ret=true;
	int l=vec[ind].S.F,r=vec[ind].S.S;
	for(auto x:seg){
		if(x.S.S<=l)ret&=true;
		else if(r<=x.S.F)ret&=true;
		else ret&=false;
	}
	return ret;
}

void handel(int ind){
	seg.clear();
	seg.push_back(vec[ind]);
	mrk[ind]=true;
	for(int i=ind;i>=0;i--){
		if(mrk[i]==false&&tadakhol(i))
			seg.push_back(vec[i]),mrk[i]=true;
	}
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			vec.push_back({j-i+1,{i,j}});
	sort(vec.begin(),vec.end());
	int res=0;
	for(int i=vec.size()-1;i>=0;i--)
		if(mrk[i]==false)
			res++,handel(i);
	cout<<res<<endl;
}
