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
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll nxt(ll n){
  ll p=1;

  if(n && !(n&(n-1))) return n;

  while(p<n) p<<=1;

  return p;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;
  ll a[n];
  map<ll,ll> mp;

  ll mx=0;
  fr(i,0,n){
    cin>>a[i];
    mp[a[i]]++;
    mx=max(mx,a[i]);
  }

  map<ll,ll> g;

  ll x;
  fr(i,0,n){
    x=nxt(a[i]);
    if(x==a[i]) x=nxt(a[i]+1);
    //cout<<a[i]<<" : ";
    while(x-a[i]<=mx){//000000){
      //cout<<x-a[i]<<" ";
      if(x-a[i]!=a[i] && mp[x-a[i]]>=1){
        g[a[i]]=1;
        g[x-a[i]]=1;
        break;
      }
      else if(x-a[i]==a[i] && mp[a[i]]>=2){
        g[a[i]]=1;
        break;
      }
      else x=nxt(x+1);
    }
    //cout<<"\n";
  }

  ll ans=0;
  fr(i,0,n) if(!g[a[i]]) ans++;
  cout<<ans;

  return 0;
}
