#include<bits/stdc++.h>
using namespace std;
long long n,ans;
map<int,int> a,b;


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		ans+=a[x+y]++;
		ans+=b[x-y]++;
	}
	cout<<ans;
}