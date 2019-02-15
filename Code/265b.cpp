#include<bits/stdc++.h>
using namespace std;
long long n,h[100007],ans;

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		if(h[i]==h[i-1])ans+=2;
		else{ans+=abs(h[i]-h[i-1]);ans+=2;}
	}
	cout<<ans-1;
}