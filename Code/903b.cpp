///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=1e5+7;

int32_t main(){
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int jon,jonesh,a1,a2,c;cin>>jon>>a1>>c>>jonesh>>a2;
	vector<bool>vec;
	while(true){
		if(jon>a2)vec.push_back(1),jonesh-=a1;
		else {
			if(jonesh<=a1)vec.push_back(1),jonesh-=a1;
			else jon+=c,vec.push_back(0);
		}
		if(jonesh<=0)break;
		jon-=a2;
	}
	cout<<vec.size()<<endl;
	for(auto x:vec)cout<<(x?"STRIKE \n":"HEAL \n");
}
