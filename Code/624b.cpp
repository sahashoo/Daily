#include<bits/stdc++.h>
using namespace std;
set<int> s;
long long n,ans;

int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		long long a;
		cin>>a;
		for(long long j=a;j>=0;j--)if(s.count(j)==0){s.insert(j);ans+=j;break;}
	}
	cout<<ans;
}