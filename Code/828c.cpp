///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
using namespace std;
const int maxn=5e6+7;
char c[maxn];
int n,maxi,nxt[maxn];

int findnxt(int k){return c[k]=='&'?k:nxt[k]=findnxt(nxt[k]);}

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for(int i=0;i<maxn-2;i++)c[i]='&',nxt[i]=i+1;
	cin>>n;
	for(int i=0;i<n;i++){
		string s;
		int k;
		cin>>s>>k;
		for(int j=0;j<k;j++){
			int ind,id;
			cin>>ind;ind--;
			id=findnxt(ind);
			while(id-ind<s.size())c[id]=s[id-ind],id++;
			maxi=max(maxi,id);
		}
	}
	for(int i=0;i<maxi;i++)cout<<(c[i]=='&'?'a':c[i]);
}
