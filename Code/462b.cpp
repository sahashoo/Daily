#include<bits/stdc++.h>
using namespace std;
long long n,k,a[30],ans;
string s;

int main(){
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)a[s[i]-'A']++;
	sort(a,a+30);
	for(int i=29;i>=0;i--){
		if(a[i]<k){ans+=a[i]*a[i];k-=a[i];a[i]=0;}
		if(k<=a[i]){ans=ans+(k*k);a[i]-=k;k=0;break;}
	}
	cout<<ans;
}