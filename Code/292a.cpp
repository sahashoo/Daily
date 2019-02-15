#include<bits/stdc++.h>
using namespace std;
const int maxn=1e3+7;
int n,w[maxn],maxw,task,t[maxn],c[maxn];

int main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t[i]>>c[i];
		if(t[i]>=task){task=t[i]+c[i];w[i]=c[i];}
		else{task+=c[i];w[i]=w[i-1]+c[i]+t[i-1]-t[i];}
		maxw=max(w[i],maxw);
	}
	cout<<task<<" "<<maxw;
}