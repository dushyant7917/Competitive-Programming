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

ll lcm(vector<ll> v) {
    ll n=SZ(v);

    ll mn=0;
    fr(i,0,n) mn=max(mn,v[i]);

    ll res=1,x=2;

    while(x<=mn) {
        vector<ll> ind;
        fr(i,0,n) if(v[i]%x==0) ind.PB(i);

        if(SZ(ind)>=2) {
            fr(i,0,SZ(ind)) v[ind[i]]=v[ind[i]]/x;
            res=res*x;
        }
        else x++;
    }

    fr(i,0,n) res=res*v[i];

    return res;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    ll t;
    cin>>t;

    ll n;
    while(t--){
        cin>>n;
        ll p[n+1],a[n+1];
        fr(i,1,n+1) cin>>p[i];

        ll cnt=0,j;
        fr(i,1,n+1){
            if(p[i]==i){
                a[i]=0;
                continue;
            }

            cnt=1;
            j=i;
            while(p[j]!=i){
                j=p[j];
                cnt++;
            }
            a[i]=cnt;
        }

        //fr(i,1,n+1) cout<<a[i]<<" "; cout<<"\n";

        vector<ll> v;
        fr(i,1,n+1) if(a[i]!=0) v.PB(a[i]);

        ll ans;

        if(!SZ(v)) ans=0;
        else {
            ans=lcm(v);
        }
        cout<<ans<<"\n";

    }

  return 0;
}
