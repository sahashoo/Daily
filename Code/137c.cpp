#include<bits/stdc++.h>
#define S second
#define F first
using namespace std;
pair<int,int>a[100010];

int main(){
	int n;cin>>n;
	for(int i=0;i<n;i++){
		int c,b;cin>>c>>b;
		a[i]={c,b};
	}
	sort(a,a+n);
	int mx=0,cnt=0;
	for(int i=0;i<n;i++){
		if(a[i].S<mx)cnt++;
		else mx=a[i].S;
	}
	cout<<cnt;
}