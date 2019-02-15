///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
int n,k;
vector<int>res;

void pn(int a){
	int num=a;
	for(int i=2;i<a;i++){
		while(num%i==0){
			//cout<<i<<endl;
			num=num/i;
			res.push_back(i);
		}
	}
	if(num!=1)res.push_back(num);
}

int32_t main(){
	//ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin>>n>>k;
	pn(n);
	if(res.size()<k)return cout<<-1,0;
	else{
		//cout<<res.size()<<endl;
		for(int i=0;i<k-1;i++)cout<<res[i]<<" ",n/=res[i];
		cout<<n;
	}

}
