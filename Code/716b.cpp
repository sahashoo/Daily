#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e4+7;
string s;

int32_t main(){
    cin>>s;
    if(s.size()<26)return cout<<-1,0;
    for(int i=0;i<s.size()-25;i++){
        set<int>st;st.clear();int qm=0;
        for(int j=i;j<i+26;j++){
            if(s[j]=='?')qm++;
            else st.insert(s[j]);
        }
        if(qm+st.size()==26){
            for(int j=i;j<i+26;j++){
                if(s[j]=='?'){
                    for(char c='A';c<='Z';c++){
                        if(st.count(c)==0){
                            s[j]=c;
                            st.insert(c);
                            break;
                        }
                    }
                }
            }
            for(int j=0;j<s.size();j++)if(s[j]=='?')s[j]='A';
            cout<<s;
            return 0;
        }
    }
    cout<<-1;
}
