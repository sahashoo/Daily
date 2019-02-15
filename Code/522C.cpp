///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
int a[40],cnt;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int w,m;cin>>w>>m;
	while(m)a[cnt++]=m%w,m/=w;
	for(int i=0;i<=cnt;i++)
		if(a[i]>1&&a[i]!=w-1&&a[i]!=w)return cout<<"NO",0;
		else if(a[i]==w-1||a[i]==w)a[i+1]++;
	cout<<"YES";
}