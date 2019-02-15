#include<bits/stdc++.h>
using namespace std;
int n,h[110000],e,p;
int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>h[i];
		int hc=h[i-1]-h[i];
		if(e+hc<0){
			p=p-(e+hc);
			e=0;
		}
		else e=e+hc;
	}
	cout<<p;
}