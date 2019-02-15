///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int cnt=0,n,k;
	string s;
	cin>>n>>k>>s;
	bool c=true;
	s=s+"&&";
	if(k==2){
		int a=0,b=0;
		for(int i=0;i<n;i++)
			if(i%2)a+=s[i]!='B';
			else a+=s[i]!='A';
		for(int i=0;i<n;i++)
			if(i%2)b+=s[i]!='A';
			else b+=s[i]!='B';
		cout<<min(a,b)<<endl;
		for(int i=0;i<n;i++)
			if((i%2&&b<=a)||(i%2==0&&b>a))cout<<'A';
			else cout<<'B';
		return 0;
	}
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1])continue;
		cnt++;
		char cmp='A';
		while(s[i]==cmp||s[i+1]==cmp)cmp++;
		s[i]=cmp;
	}
	cout<<cnt<<endl<<s.substr(0,n);
}
