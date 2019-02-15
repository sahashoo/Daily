#include<bits/stdc++.h>
using namespace std;
double n,k,sum,ch,kh;

int main(){
	cin>>n>>k;
	kh=k-0.5;
	for(int i=0;i<n;i++){int a;cin>>a;sum+=a;}
	ch=sum/(double)n;
	int ans=0;
	while(ch<kh){
		sum+=k;
		ans++;
		ch=sum/(double)(n+ans);
	}
	cout<<ans;
}