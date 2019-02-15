#include<bits/stdc++.h>
using namespace std;
int n,res;
string s;

int32_t main(){
	cin>>n>>s;res++;
	for(int i=1;i<n;i++)if(s[i]!=s[i-1])res++;
	cout<<min(res+2,n);
}