#include<bits/stdc++.h>
#define F first
#define S second
#define pb push_back
using namespace std;
const int N=2e5+7;
vector<pair<int,int> >a;

int32_t main(){
	int n;cin>>n;
	for(int i=0,l=0,r=0;i<n;i++)cin>>l>>r,a.pb({l,+1}),a.pb({r+1,-1});
	sort(a.begin(),a.end());
	int tmp=0;
	for(int i=0;i<a.size();i++){
		tmp+=a[i].S;
		if(tmp>2)return cout<<"NO",0;
	}
	cout<<"YES";
}