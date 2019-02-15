#include<bits/stdc++.h>
using namespace std;
long long r,b,g,a,z;

int main(){
	cin>>r>>g>>b;
	a=min(r+g,min(b+r,g+b));
	z=(r+g+b)/3;
	cout<<min(a,z);
}