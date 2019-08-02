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

  ll n;
  while(t--){
    cin>>n;

    ll a[n];
    fr(i,0,n) cin>>a[i];

    sort(a,a+n);

    if(a[0]==1){
      cout<<0<<"\n";
      continue;
    }

    ll ans=0;
    bool flag;

    ll mark[n]={0};

    rf(i,n-1,1){
      flag=false;

      fr(j,0,i){
        if(a[i]%a[j]==0){
          flag=true;
          ans++;
          break;
        }
        if(flag) mark[i]=1;
      }
    }

    ll f=a[0];

    fr(i,1,n){
      if(mark[i]) continue;
      f=__gcd(f,a[i]);
    }

    if(f==1) cout<<ans<<"\n";
    else cout<<-1<<"\n";
  }

  return 0;
}