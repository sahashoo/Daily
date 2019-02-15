///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define size(a) (int)a.size()
#define int long long
#define F first
#define S second
#define pb push_back
#define bug cout<<"\n\n************"
using namespace std;
void null(){return ;}
const int maxn=5e5+100,INF=3e18+9237,mod=1e9+7;
string s,t;
int n,m,p,pr[maxn],mrk[maxn],l[maxn],r[maxn];//,outputsum[maxn];
stack<int> stk;

void preprocess(){
	s=" "+s;
	for(int i=1;i<=n;i++){
		if(s[i]=='(')stk.push(i);
		else pr[i]=stk.top(),pr[stk.top()]=i,stk.pop();
		r[i]=i+1;
		l[i]=i-1;
	}
}

int del(int id){
	if(s[id]=='('){
		r[l[id]]=r[pr[id]];
		l[r[pr[id]]]=l[id];
		if(r[pr[id]]!=1+n)return r[pr[id]];
		return l[id];
	}
	else{
		l[r[id]]=l[pr[id]];
		r[l[pr[id]]]=r[id];
		if(r[id]!=1+n)return r[id];
		else return l[pr[id]];
	}
}

void output(){
	int ind;
	for(int i=1;i<=n;i++)if(l[i]==0)ind=i;
	while(ind!=n+1)cout<<s[ind],ind=r[ind];
}

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m>>p>>s>>t;
	preprocess();
	for(int i=0;i<m;i++){
		if(t[i]=='L'&&l[p]!=0)p=l[p];
		if(t[i]=='R'&&r[p]!=n+1)p=r[p];
		if(t[i]=='D')p=del(p);
	}
	output();
}