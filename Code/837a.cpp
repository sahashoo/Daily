#include<bits/stdc++.h>
using namespace std;
char c[250];

int32_t  main(){
	int n;cin>>n;
	int cnt=0,res=0;
	getchar();
	while(n--){
		char c=getchar();
		if(c<'A')cnt=0;
		else if(c<='Z')cnt++;
		res=max(res,cnt);
	}
	cout<<res;
}