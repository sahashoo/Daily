///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	if(n<5)return cout<<n*(n-1)/2,0;
	int tmp=9,res=0;
	while(2*n-1>=tmp)tmp=tmp*10+9;
	tmp/=10;
	for(int i=0;i<9;i++){
		int temp=i*(tmp+1)+tmp;
		if(2*n-1<temp)break;
		res+=min(n,temp-1)-temp/2;
	}
	cout<<res;
}
