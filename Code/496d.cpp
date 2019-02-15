///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7,INF=1e18+7,mod=1e9+7;
int n;
vector<int>a,b;
vector<pair<int,int> >res;

int findnxta(int ind,int t){return(ind+t>a.size()?INF:a[ind+t-1]+1);}
int findnxtb(int ind,int t){return(ind+t>b.size()?INF:b[ind+t-1]+1);}

int can(int t){
	int s=0,ma=0,mb=0,lst=0,i=0,j=0;
    while(i<a.size()||j<b.size()){
		//cout<<"HERE"<<t<<endl;
        int mna=findnxta(i,t),mnb=findnxtb(j,t);
		int mn=min(mna,mnb);
		if(mn==INF)return -1;
		if(mn==mna)lst=1,ma++,s=ma;
		if(mn==mnb)lst=2,mb++,s=mb;
        i=lower_bound(a.begin()+i,a.end(),mn)-a.begin();
        j=lower_bound(b.begin()+j,b.end(),mn)-b.begin();
    }
	if(i==a.size()&&j==b.size()&&((lst==1&&ma>mb)||(lst==2&&ma<mb)))return s;
	else return -1;
}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		if(x==1)a.push_back(i);
		else b.push_back(i);
	}
	for(int i=1;i<=n;i++){
		int s=can(i);
		if(s!=-1)res.push_back({s,i});
	}
	sort(res.begin(),res.end());
	cout<<res.size()<<endl;
	for(auto a:res)cout<<a.F<<" "<<a.S<<endl;
}
