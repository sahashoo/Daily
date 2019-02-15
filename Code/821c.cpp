#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=3e5+7;
int n,ans,maxd,a[maxn],cnt,last,cnt2;
string s;
set<int>mys;

int32_t main(){
    cin>>n;
    for(int i=1;i<=2*n;i++){
        cin>>s;
        if(s=="add"){
            int c;cin>>c;
            cnt2++;
            a[c]=cnt2;
            mys.insert(cnt2);
        }
        else{
            cnt++;
            maxd=*(mys.rbegin());
            if(maxd!=a[cnt]&&maxd>last){
                last=cnt2;
                ans++;
            }
            mys.erase(a[cnt]);
        }
    }
    cout<<ans<<endl;
}
