#include<bits/stdc++.h>
using namespace std;
int n,l,r,s,m,c,d[110000];
int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		cin>>l>>r;
		d[i]=l-r;
		s=s+l-r;
	}
	m=s;
	for(int i=0;i<n;i++){
		if(abs(-2*d[i]+s)>abs(m)){
			c=i+1;
			m=-2*d[i]+s;
		}
	}
	cout<<c;
}