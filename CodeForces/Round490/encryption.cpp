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

vector<ll> div(ll n){
  vector<ll> v;

  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      v.PB(i);
      if(n/i!=i) v.PB(n/i);
    }
  }

  return v;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  string s;
  cin>>n>>s;

  vector<ll> d=div(n);
  sort(d.begin(),d.end());
  
  char c[n];
  fr(i,0,SZ(s)) c[i]=s[i];

  fr(i,0,SZ(d)) reverse(c,c+d[i]);

  fr(i,0,n) cout<<c[i];


  return 0;
}
