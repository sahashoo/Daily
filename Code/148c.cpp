#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e5+7;
const int INF=1e9+7;
int a,b,n,t,sum;
vector<int>res;

int32_t main(){
	cin>>n>>a>>b;
	if(a==n-1&&a!=0)return cout<<-1,0;
	res.push_back(1);
	t++;sum++;
	for(int i=1;i<=b;i++){
		res.push_back(sum+1);
		t=sum+1;sum+=sum+1;
	}
	if(b==0){
		res.push_back(t);
		b=1;
	}
	for(int i=b+1;i<a+1+b;i++){
		t++;
		res.push_back(t);
	}
	for(int i=a+b+1;i<n;i++)res.push_back(t);
	//cout<<endl;
	for(int i=0;i<n;i++)cout<<res[i]<<" ";
}
