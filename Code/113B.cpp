///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int B=1e9+9;
string s,a,b;
vector<int> v1,v2,ans;
int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>s>>a>>b;
	int p=0;
	while(p=s.find(a,p)+1)v1.push_back(p);
	while(p=s.find(b,p)+1)v2.push_back(p);
    for(int i=0;i<v1.size();i++){
        int j=0,h=0;
        for(int k=v1[i];k<=s.size();k++){
	        while(j<v2.size()&&v2[j]<k) j++;
	        if(j<v2.size()&&v2[j]==k&&k+b.size()>=v1[i]+a.size()) ans.push_back(h);
	       	h=h*B+(s[k-1]-'a'+1);
    	}
	}
	sort(ans.begin(),ans.end());
	cout<<unique(ans.begin(),ans.end())-ans.begin();
}
