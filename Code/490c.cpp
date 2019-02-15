///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e6+7;
int a,b,c[maxn],suf[maxn],pre[maxn],d=1;
string s;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>s>>a>>b;
	int n=s.size();
	for(int i=1;i<=n;i++){
		c[i]=s[i-1]-'0';
		pre[i]=((pre[i-1]*10)+c[i])%a;
	}
	for(int i=n;i>=1;i--){
		suf[i]=((c[i]*d)+suf[i+1])%b;
		d*=10;d%=b;
	}
	
	/*for(int i=0;i<=n;i++)cout<<pre[i]<<" ";
	cout<<endl;
	for(int i=0;i<=n;i++)cout<<suf[i]<<" ";
	cout<<endl;*/
	
	for(int i=1;i<n;i++){
		if(suf[i+1]==0&&pre[i]==0){	
			string t=s.substr(0,i);
			for(i=i;i<n;i++){
				if(s[i]=='0')t+='0';
				else break;
			}
			if(i>=n)return cout<<"NO",0;
			string d=s.substr(i,n);
			cout<<"YES"<<endl<<t<<endl<<d;
			return 0;
		}
	}
	cout<<"NO";
}
