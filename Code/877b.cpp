///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e3+7;
int a[maxn],b[maxn];

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	string s;cin>>s;
	int n=s.size();
	for(int i=0;i<n;i++)
		a[i+1]=a[i]+(s[i]=='a'),
		b[i+1]=b[i]+(s[i]=='b');
	int mx=0;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)
			mx=max(mx,a[n]-a[j]+b[j]-b[i-1]+a[i]);
	cout<<mx;
}
