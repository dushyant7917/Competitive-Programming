#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define fi first
#define se second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

ll sign(char c) {
    if(c=='R') return 0;
    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    string s;
    ll cnt,cntR,cntG,R,G;
    while(t--){
        cin>>s;

        if(SZ(s)==1) {
            cout<<"yes\n";
            continue;
        }

        cnt=cntR=cntG=0;

        fr(i,0,SZ(s)) {
            if(s[i]=='G') cntG++;
            else cntR++;
        }

        if(cntG!=cntR) {
            cout<<"no\n";
            continue;
        }

        s+=s[0];
        G=R=0;
        fr(i,1,SZ(s)) {
            if(sign(s[i])==sign(s[i-1])) {
                cnt++;
                if(s[i]=='G') G=1;
                else R=1;
            }
        }

        if((cnt==2 && R && G) || !cnt) cout<<"yes\n";
        else cout<<"no\n";
    }

    return 0;
}
