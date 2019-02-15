#include<bits/stdc++.h>
#define int long long
#define w second
#define q first
using namespace std;
const int maxn=1e6+7;
int siz[maxn],n,k;
string s;

bool check(int x){
	int now=0,t=0;
	for(int i=0;i<n;i++){
		if(siz[i]+now<=x)now+=siz[i];
		else{
			t++;
			now=siz[i];
            if(now>x)return false;
		}
	}
	if(t>=k)return false;
	else return true;
}

int32_t main(){
	cin>>k;
	getchar();
	getline(cin,s);
	for(int i=0;i<s.size();i++){
		siz[n]++;
		if(s[i]==' '||s[i]=='-')n++;
	}
	n++;
	int l=0,r=s.size()+1;
	while(1<r-l){
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	cout<<r<<endl;
}
