#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>=b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 10000001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll ans[N];

vector<ll> factors(ll n){
  vector<ll> v;

  for(ll i=1;i*i<=n;i++){
    if(n%i==0){
      if(n/i==i) v.PB(i);
      else{
        v.PB(i);
        v.PB(n/i);
      }
    }
  }

  return v;
}

ll x;

bool check(ll n,ll c,vector<ll> f,ll ind){
  rf(i,n-1,0){
    x=i;
    while(c%f[ind]!=0) ind--;
    c/=f[ind];
    ans[i]=f[ind]+i;
    if(ind!=SZ(f)-1 && f[ind]==f[ind+1]-1) ind++;
    if(ind==0 || c==1) break;
  }

  return (c==1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,c;
  while(t--){
    cin>>n>>c;

    vector<ll> f=factors(c);
    sort(f.begin(),f.end());

    fr(i,0,SZ(f)){
      if(check(n,c,f,i)){
        fr(j,0,x) ans[j]=j+1;
        break;
      }
    }

    fr(i,0,n) cout<<ans[i]<<" "; cout<<"\n";
  }

  return 0;
}
