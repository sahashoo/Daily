#include<bits/stdc++.h>
using namespace std;
int n,k1,k2;
queue<int> a,b;

int main(){
	cin>>n>>k1;
	for(int i=0;i<k1;i++){int l;cin>>l;a.push(l);}
	cin>>k2;
	for(int i=0;i<k2;i++){int l;cin>>l;b.push(l);}
	for(int i=1;i<150;i++){
		int aa=a.front(),bb=b.front();
		a.pop();
		b.pop();
		if(aa>bb){a.push(bb);a.push(aa);}
		if(bb>aa){b.push(aa);b.push(bb);}
		if(a.empty()&&!b.empty()){cout<<i<<" "<<"2";return 0;}
		if(b.empty()&&!a.empty()){cout<<i<<" "<<"1";return 0;}
	}
	cout<<"-1";
}