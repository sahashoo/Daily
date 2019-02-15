///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=2e5+7;
int a[MAXN],suf[MAXN];
bool prf[MAXN];
set<int>st;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
		auto x=st.upper_bound(a[i]);
		auto xx=x;//xx++;
		// cout<<"----- "<<i<<endl;
		if(x==st.end())prf[a[i]]=true;
		else if(++xx==st.end())suf[*x]++;
		st.insert(a[i]);
	}
	// cout<<"HERE"<<endl;
	int pnt=1;
	for(int i=2;i<=n;i++)
		if(suf[i]-prf[i]>suf[pnt]-prf[pnt])pnt=i;
	cout<<pnt;
	return 0;
}
