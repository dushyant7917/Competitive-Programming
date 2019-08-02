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

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll t;
  cin>>t;

  ll n,l,r;
  bool flag;

  while(t--){
    cin>>n;
    ll a[n];
    fr(i,0,n) cin>>a[i];

    if(n&1){
      cout<<"NO\n";
      continue;
    }

    flag=true;
    l=0;
    r=n/2;

    while(l<n){
      if(a[l]==-1 && a[r]==-1) a[l]=a[r]=1;
      else if(a[l]==-1 && a[r]!=-1) a[l]=a[r];
      else if(a[l]!=-1 && a[r]==-1) a[r]=a[l];
      else if(a[l]!=a[r]){
        cout<<"NO\n";
        flag=false;
        break;
      }
      else {}
      l++;
      r++;
      r%=n;
    }

    if(!flag) continue;

    cout<<"YES\n";
    fr(i,0,n) cout<<a[i]<<" "; cout<<"\n";
  }

  return 0;
}
