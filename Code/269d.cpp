#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
int n,a,b,par[maxn],vs[maxn],sta[maxn],arr[maxn];
map<int,int> m;

int find(int x){return par[x]==x?x:par[x]=find(par[x]);}

int main(){
	cin>>n>>a>>b;
	for(int i=1;i<=n;i++)cin>>arr[i],m[arr[i]]=i,par[i]=i;
	for(int i=1;i<=n;i++){
		if(m.count(a-arr[i]))par[find(m[a-arr[i]])]=find(i),vs[i]|=1;
		if(m.count(b-arr[i]))par[find(m[b-arr[i]])]=find(i),vs[i]|=2;
	}
	for(int i=1;i<=n;i++)sta[i]=3;
	for(int i=1;i<=n;i++)sta[find(i)]&=vs[i];
	for(int i=1;i<=n;i++)if(sta[find(i)]==0)return cout<<"NO",0;
	cout<<"YES"<<endl;
	for(int i=1;i<=n;i++)cout<<(sta[find(i)]+1)%2<<" ";
}