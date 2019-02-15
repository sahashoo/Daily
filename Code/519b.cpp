///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
#define F first
#define S second
using namespace std;
const int maxn=1e5+7;
int n;
map<int,int>a,b;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n;
	for(int i=0;i<n;i++){
		int c;cin>>c;
		a[c]++;
	}
	for(int i=1;i<n;i++){
		int c;cin>>c;
		b[c]++;a[c]--;
		if(a[c]==0)a.erase(c);
	}
	for(int i=2;i<n;i++){
		int c;cin>>c;
		b[c]--;
		if(b[c]==0)b.erase(c);
	}
	for(auto x:a)cout<<x.F<<endl;
	for(auto x:b)cout<<x.F<<endl;
	
}
