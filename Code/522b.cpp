#include<bits/stdc++.h>
using namespace std;
const int N=2e5+7;
int w[N],h[N],W,h1,h2;

int32_t main(){
	int n;cin>> n;
	for(int i=0;i<n;i++){
		cin>>w[i]>>h[i];
		W+=w[i];
		if(h1<=h[i])h2=h1,h1=h[i];
		else if(h2<=h[i])h2=h[i];
	}
	for(int i=0;i<n;i++)
		cout<<(W-w[i])*(h[i]==h1?h2:h1)<<" ";
}