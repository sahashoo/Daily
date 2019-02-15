#include <bits/stdc++.h>
using namespace std;
int n,p[110000],q,x;

int bs(int l,int r,int s){
	int z=(l+r)/2;
	if(p[z]==s&&p[z+1]>s)	return z+1;
	else if(p[z]>s&&p[z-1]<=s)	return z;
	else if(p[z]>s)	return bs(l,z,s);
	else	return bs(z+1,r,s);
}

int main(){
	cin>>n;
	for(int i=0;i<n;i++) cin>>p[i];
	sort(p,p+n);
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>x;
		if (x<p[0])	cout<<"0"<<endl;
		else if(x>=p[n-1]) cout<<n<<endl;
		else cout<<bs(0,n-1,x)<<endl;
	}
}