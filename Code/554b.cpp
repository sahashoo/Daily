#include<bits/stdc++.h>
using namespace std;
int n,ans;
map<string,int> mp;


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		mp[s]+=1;
		ans=max(ans,mp[s]);
	}
	cout<<ans;
}