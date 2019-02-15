#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+1000;
string s;
int m,l[MAXN],r[MAXN],ans[MAXN];

int main(){
	cin>>s>>m;
	for(int i=0;i<m;i++){
		cin>>l[i]>>r[i];
	}
	for(int i=0;i<s.size()-1;i++){
		ans[i+1]=ans[i];
		if(s[i]==s[i+1]){
			ans[i+1]++;
		}
	}
	for(int i=0;i<m;i++){
		cout<<ans[r[i]-1]-ans[l[i]-1]<<endl;
	}
}