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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n>>m;

  ll a[n+1],ps[n+1]={0};

  fr(i,1,n+1) cin>>a[i];

  fr(i,1,n+1){
    if(a[i]<m) ps[i]=-1;
    else if(a[i]>m) ps[i]=1;
    else ps[i]=0;
  }

  fr(i,1,n+1) ps[i]+=ps[i-1];

  bool flag=false;
  map<ll,ll> mp;
  ll ans=0;

  fr(i,0,n+1){
    if(a[i]==m) flag=true;

    if(flag) ans+=mp[ps[i]]+mp[ps[i]-1];
    else mp[ps[i]]++;
  }

  cout<<ans;

  return 0;
}
