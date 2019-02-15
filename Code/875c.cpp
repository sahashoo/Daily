///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
vector<int>ans;

int sum(int a){
	int res=0;
	while(a)res+=a%10,a/=10;
	return res;
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	int a;
	if(n>90)a=n-90;
	else a=1;
	for(int i=max(1,n-90);i<n;i++)
		if(sum(i)+i==n)ans.push_back(i);
	cout<<ans.size()<<endl;
	for(int i=0;i<ans.size();i++)cout<<ans[i]<<" ";
}
