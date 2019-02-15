#include<bits/stdc++.h>
#define int long long
using namespace std;
int t,d,sum,v1,v2;

int32_t main(){
	cin>>v1>>v2>>t>>d;
	for(int i=0;i<t;i++)sum+=min(v1+(i*d),v2+(d*(t-i-1)));
	cout<<sum;
}