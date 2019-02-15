///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=5e3+7;
const int mod=1e9+7;
int a[MAXN],ta;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n;cin>>n;
	char c,p='0';
	a[0]=1;
	for(int ind=0;ind<n;ind++){
		cin>>c;
		if(p=='s'){
			int sum=0;
			for(int i=0;i<=ta;i++)
				sum=(sum+a[i])%mod,a[i]=sum;
		}
		if(c=='f')a[++ta]=0;
		p=c;
	}
	int sum=0;
	for(int i=0;i<=ta;i++)
		sum=(sum+a[i])%mod,a[i]=sum;
	cout<<sum;
}