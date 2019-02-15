///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define ld long double
#define int long long
#define F first
#define S second
using namespace std;
void null(){return ;}
const int INF=3e18+9237;
const int maxn=1e6+7;
const int mod=1e9+7;
const int sqN=320;
const int lgN=20;
int arr[maxn];

int32_t main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	int a;cin>>a;
	arr[0]=1;
	for(int i=1;i<maxn;i++){
		arr[i]=arr[i-1]+(i%2?0:1);
		if(arr[i]==a){
			cout<<i;break;
		}
	}
	cout<<" 2\n1 2";
}
