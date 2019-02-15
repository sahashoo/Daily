///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+7;
vector<string>vc1,vc2,vc3;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s,t,tmp="";cin>>s>>t;
	for(int i=0;i<s.size();i++)
		tmp=tmp+s[i],vc1.push_back(tmp);
	tmp="";
	for(int i=0;i<t.size();i++)
		tmp=tmp+t[i],vc2.push_back(tmp);
	
	for(string i:vc1)
		for(string j:vc2)
			vc3.push_back(i+j);
	sort(vc3.begin(),vc3.end());
	
	cout<<vc3[0];
}
