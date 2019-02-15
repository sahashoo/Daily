///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+7;
int prf[N],ind;
bool mrk[N];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	for(int i=1;i<s.size();i++){
		while(ind&&s[i]!=s[ind])ind=prf[ind-1]; 
		if(s[i]==s[ind])ind++;
		if(i<s.size()-1)mrk[ind]=true;		
		prf[i]=ind;
		// cout<<ind<<" "<<prf[i]<<'\n';
	}
	mrk[0]=true,ind=prf[s.size()-1];
	while(ind&&mrk[ind]==false)ind=prf[ind-1];
	if(ind)cout<<s.substr(0,ind);
	else cout<<"Just a legend";
}
