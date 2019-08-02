#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

vector<ll> factors(ll n,ll limit){
  vector<ll> f;
  ll r=sqrt(n)+1;

  fr(i,1,r+1){
    if(n%i==0){
      if(i==0 || n/i==0) cout<<i<<"\n";
      if(i<=limit) f.PB(i);
      if(n/i!=i && n/i<=limit) f.PB(n/i);
    }
  }

  sort(f.begin(),f.end());

  return f;
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,a,b,c,r;
  while(t--){
    cin>>n>>a>>b>>c;

    vector<ll> x,y;
    x=factors(n,a);

    ll cnt=0,rem,p,q;

    map<pii,ll> mp;

    fr(i,0,SZ(x)){
      rem=n/x[i];
      y=factors(rem,b);
      fr(j,0,SZ(y)){
        p=y[j];
        q=rem/y[j];
        if(p<=b && q<=c && p!=q && mp[pii(p,q)]==0){
          cnt++;
          mp[pii(p,q)]=1;
          if(q<=b && p<=c && mp[pii(q,p)]==0){
            cnt++;
            mp[pii(q,p)]=1;
          }
        }
        else if(p<=b && q<=c && p==q){
          cnt++;
        }
        else {}
      }
    }

    cout<<cnt<<"\n";
  }

  return 0;
}
