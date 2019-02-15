#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a,b,c,x,ans;
int main(){
	cin>>a>>b>>c;
	x=max(max(a,b),c);
	if(x>a)ans+=x-a-1;
	if(x>b)ans+=x-b-1;
	if(x>c)ans+=x-c-1;
	cout<<ans;
}