///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int k,a,b;
string s;
	
int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>k>>a>>b>>s;
	int n=s.size();
	if((n%k&&(n/k+1>b)||(n/k<a||n/k>b)))
		return cout<<"No solution",0;
	int ind=0;
	for(int i=0;i<n%k;i++){
		for(int j=ind;j<ind+n/k+1;j++)
			cout<<s[j];cout<<endl;
		ind+=n/k+1;
	}
	for(int i=0;i<k-(n%k);i++){
		for(int j=ind;j<ind+n/k;j++)
			cout<<s[j];cout<<endl;
		ind+=n/k;
	}
}
