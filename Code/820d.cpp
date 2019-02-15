#include<bits/stdc++.h>
#define int long long
#define q first
#define w second
using namespace std;
const int maxn=1e6+7;
const int INF=1e9+7;
int id,dev,mind,n,p[maxn],a[maxn],l;

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>n;
	for(int i=1;i<=n;++i){
        cin>>p[i];
        dev+=abs(p[i]-i);
        a[(p[i]-i+n)%n]++;
        p[i]<i?l++:l--;
	}
	mind=dev;
	for(int i=0;i<n-1;i++){
        l+=2*a[i]-2;
        dev+=abs(p[n-i]-1)-abs(p[n-i]-n)+l+1;
        if(dev<mind){
            mind=dev;
            id=i+1;
        }
	}
	cout<<mind<<" "<<id;

}
