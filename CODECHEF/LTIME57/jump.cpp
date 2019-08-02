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
#define N 100001
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,u,d;
  while(t--){
    cin>>n>>u>>d;
    ll h[n];
    fr(i,0,n) cin>>h[i];

    ll i=1,f=1,use=0;
    while(i<=n-1 && f){
      //cout<<i-1<<" "<<i<<"\n";
      if(h[i]==h[i-1]) i++;
      else if(h[i]>h[i-1] && h[i]-h[i-1]<=u) i++;
      else if(h[i]<h[i-1] && h[i-1]-h[i]<=d) i++;
      else if(h[i]<h[i-1] && h[i-1]-h[i]>d && use==0){
        i++;
        use=1;
      }
      else f=0;
    }

    cout<<i<<"\n";
  }

  return 0;
}
