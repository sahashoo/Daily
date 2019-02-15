#include <bits/stdc++.h>
using namespace std;
long long e,d,c,r,b;
main(){
    cin>>r>>b>>c>>d>>e;
    cout<<ceil(sqrt(((pow(b-d,2)+pow(c-e,2))))/(2*r));
}