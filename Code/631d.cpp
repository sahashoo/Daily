// #include<bits/stdc++.h>
// #define int long long
// #define F first
// #define S second
// #define all(a) a.begin(),a.end()
// using namespace std;
// const int N=2e5+7;
// int arr[N],ans;

// struct STRING
// {
    // char c;
    // int l;
    // bool operator==(const STRING &b)
	// {
        // return c==b.c&&l==b.l;
    // }
	// bool operator!=(const STRING &b)
	// {
        // return c!=b.c||l!=b.l;
    // }
    // bool operator<=(const STRING &b)
	// {
        // return c==b.c&&l<=b.l;
    // }
// }a[N],b[N];

// void kmp(STRING *a,int &n)
// {
    // int m=0;
    // for(int i=0;i<n;i++)
	// {
        // if(m==0||a[m-1].c!=a[i].c)
            // a[m++]=a[i];
        // else
            // a[m-1].l+=a[i].l;
    // }
    // n=m;
// }

// int32_t main()
// {
	// int n,m;
	// cin>>n>>m;
	// scanf("%d%d",&n,&m);
    // for(int i=0;i<n;i++)
        // scanf("%I64d-%c",&a[i].l,&a[i].c);
	// cout<<"RIDI DADA"<<endl;
    // for(int i=0;i<m;i++)
        // scanf("%I64d-%c",&b[i].l,&b[i].c);
	
	// kmp(a,n);
	// kmp(b,m);
	
    // if(m==1)
	// {
        // for(int i=0;i<n;i++)
            // if(b[0]<=a[i])
                // ans+=a[i].l-b[0].l+1;
    // }
	// else if(m==2)
	// {
        // for(int i=0;i<n-1;i++)
            // if(b[0]<=a[i]&&b[1]<=a[i+1])
                // ans++;
    // }
	// else
	// {
        // arr[1]=0;
        // for(int i=2;i<m-1;i++)
		// {
            // int j=arr[i-1];
            // while(j>0&&!(b[j+1]!=b[i]))
                // j=arr[j];
            // if(b[j+1]==b[i])
                // j++;
            // arr[i]=j;
        // }
		// int j=0;
        // for(int i=1;i<n-1;i++)
		// {
			// cout<<"ridi dada "<<j<<endl;
            // while(j>0&&!(b[j+1]==a[i]))
                // j=arr[j];
            // if(b[j+1]==a[i])
                // j++;
            // if(j==m-2) 
			// {
                // if(b[0]<=a[i-j]&&b[j+1]<=a[i+1])
                    // ans++;
                // j=arr[j];
            // }
        // }
    // }

	// cout<<ans;
// }


/**
	In the name of God
	code by reyna
**/
#include <bits/stdc++.h>

using namespace std;


typedef long long ll;
typedef pair<ll, ll> pii;

template<class P, class Q> inline P smin(P &a, Q b) { if (b < a) a = b; return a; }
template<class P, class Q> inline P smax(P &a, Q b) { if (a < b) a = b; return a; }

#define rep(i, n) for (int i = 0, _n = (int)(n); i < _n; i++)

const int N = 4e5 + 5;

int read() { int x; cin >> x; return x; }

pii s[N], t[N], tt[N];

int get(int n, pii z[N]) {
	int last = 0, pt = 0;
	ll cnt = 0;
	rep(i, n) {
		string a;
		cin >> a;
		if (last != a[a.size() - 1]) {
//			cout << char(last) << ' ' << cnt << endl;
			if (last != 0)
				z[pt++] = {last, cnt};
			cnt = 0;
		}
		int x = 0;
		rep(j, a.size() - 2)
			x *= 10, x += a[j] - '0';
		cnt += x;
		last = a[a.size() - 1];
	}
	if (cnt) if (last != 0)
		z[pt++] = {last, cnt};
	return pt;
}

int f[N];

int32_t main() {
	ios_base :: sync_with_stdio(false); cin.tie(0); cout.tie(0);
	int n = read(), m = read();
	n = get(n, s);
	m = get(m, t);
	for (int i = 1; i < m - 1; ++i)
		tt[i - 1] = t[i];
	for (int i = 1; i < m - 2; ++i) {
		int state = f[i];
		while (state && tt[state] != tt[i])
			state = f[state];
		if (tt[state] == tt[i])
			state++;
		f[i + 1] = state;
//		cout << i << ' ' << state << endl;
	}
	ll res = 0;
	if (m == 1) {
		rep(i, n)
			if (s[i].first == t[0].first && s[i].second >= t[0].second)
				res += s[i].second - t[0].second + 1;
	} else {
		int state = 0;
		rep(i, n) {
			while (state && tt[state] != s[i])
				state = f[state];
			if (state < m && tt[state] == s[i])
				state++;
			if (state == m - 2 || m == 2) {
				int nxt = i + 1, lst = i - (m - 2);
				if (lst >= 0 && nxt < n) {
					if (s[lst].first == t[0].first && s[lst].second >= t[0].second && s[nxt].first == t[m - 1].first && s[nxt].second >= t[m - 1].second)
						res++;
				}
				state = f[state];
			}
		}
	}
	cout << res;
}