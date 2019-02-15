#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=2e5+7;
stack<int>stk;
int a[MAXN];

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int n,k,tmp=1;cin>>n>>k;
	stk.push(n+1);
	for(int i=0;i<k;i++){
		cin>>a[i];
		if(stk.top()<a[i])return cout<<-1,0;
		stk.push(a[i]);
		while(stk.top()==tmp)stk.pop(),tmp++;
	}
	for(int i=0;i<k;i++)cout<<a[i]<<" ";
	while(stk.size()){
		for(int i=stk.top()-1;i>=tmp;i--)
			cout<<i<<" ";
		tmp=stk.top()+1;
		stk.pop();
	}
}
