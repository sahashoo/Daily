#include<bits/stdc++.h>
using namespace std;
int o,n,a[1100],t,m,k=1;
main(){
    cin>>n;
    for(int i=0;i<n;i++) cin>>a[i];
    while(t<n){
        if(a[o]<=t){
			t++;
			a[o]=9999;
		}
        if(t==n) break;
        if(o+k==n||o+k<0){
			k=-k;
			m++;
		}
        o=o+k;
	}
    cout<<m<<endl;
}