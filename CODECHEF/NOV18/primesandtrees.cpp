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
#define N 20001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) ((ll)s.size())
#define MS(x,v) memset(x,v,sizeof(x))

bool prime[N];

void preProcess(){
  MS(prime,true);
  prime[0]=prime[1]=false;

  ll i,j;
  for(i=2;i*i<=N;i++){
    if(prime[i]){
      for(j=i*2;j<=N;j+=i){
        prime[j]=false;
      }
    }
  }
}


int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  preProcess();

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  vector<ll> p,cp,v;

  fr(i,0,n){
    if(prime[a[i]]) p.PB(i+1);
    else cp.PB(i+1);
  }

  fr(i,0,SZ(cp)) v.PB(cp[i]);
  fr(i,0,SZ(p)) v.PB(p[i]);

  fr(i,1,SZ(v)) cout<<v[0]<<" "<<v[i]<<"\n";

  return 0;
}
