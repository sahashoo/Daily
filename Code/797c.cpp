///age yekam bekeshi beham is no problem ._.
#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=1e5+7;
string s,ans;
stack<char>st;
int mn[maxn];

int32_t main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin>>s;
    mn[s.size()]='z'+5;
    for(int i=s.size()-1;i>=0;i--)mn[i]=min(mn[i+1],(int)s[i]);
    for(int i=0;i<s.size();i++){
        st.push(s[i]);
        while(st.size()){
            if((int)st.top()<=mn[i+1]){
                ans+=st.top();
                st.pop();
            }
            else break;
        }
    }
    cout<<ans<<endl;;
	for(int i=0;i<s.size()+1;i++)cout<<mn[i]<<" ";
}
