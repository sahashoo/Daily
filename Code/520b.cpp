#include<bits/stdc++.h>
using namespace std;
int n,m,i;
main(){
    cin>>n>>m;
    while(n<m){
        i++;
        if(m%2) m++;
        else m=m/2;
    }
    cout<<i-m+n;
}