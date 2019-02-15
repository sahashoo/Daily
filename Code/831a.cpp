///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int a[maxn],n;
bool inc,cons,dec,ans=true;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]&&cons==true)return cout<<"NO",0;
		if(a[i]>a[i-1]&&inc==true)return cout<<"NO",0;
		if(a[i]==a[i-1])inc=true;
		if(a[i]<a[i-1])cons=true,inc=true;
	}
	cout<<"YES";

}