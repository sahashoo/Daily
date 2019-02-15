#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e6+7;
int T[maxn],n;
pair<int,int>a[maxn];

void add(int i){
	for(i++;i<n;i+=i&(-i))T[i]++;
}

int get(int i){
	int tmp=0;
	for(i;i>0;i-=i&(-i))tmp+=T[i];
	return tmp;
}

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int x;cin>>x;
		a[i]={x,i};
	}
	sort(a,a+n);
	int res=0;
	for(int i=0;i<n;i++){
		int tmp=get(a[i].S);
		res+=1ll*(a[i].S-tmp)*(i-tmp);
		add(a[i].S);
	}
	cout<<res;
}