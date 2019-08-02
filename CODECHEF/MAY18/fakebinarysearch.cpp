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

ll count_less(ll b[],ll n,ll x){
  ll l=0,h=n-1,m;

  while(l<=h){
    m=(l+h)/2;
    if(b[m]==x) break;
    else if(b[m]<x) l=m+1;
    else h=m-1;
  }

  return m;
}

ll bs(ll a[],ll n,ll x,ll pos,ll less,ll more){
  ll l=0,h=n-1,m,swaps=0,ML=0,LR=0;

  while(l<=h){
    m=(l+h)/2;

    if(a[m]==x && m==pos) break;

    else if(a[m]<x && !less) return -1;

    else if(a[m]>x && !more) return -1;

    else if(a[m]==x && m!=pos) return -1;

    else if(a[m]<x && m<pos){
      less--;
      l=m+1;
    }

    else if(a[m]<x && m>pos){
      LR++;
      if(more){
        more--;
        swaps++;
        h=m-1;
      }
      else return -1;
    }

    else if(a[m]>x && m>pos){
      more--;
      h=m-1;
    }

    else if(a[m]>x && m<pos){
      ML++;
      if(less){
        less--;
        swaps++;
        l=m+1;
      }
      else return -1;
    }

    else {}
  }

  return ((m==pos && a[m]==x)?(swaps-min(ML,LR)):-1);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  ll n,q,x,less;
  while(t--){
    cin>>n>>q;
    ll a[n],b[n];
    fr(i,0,n){
      cin>>a[i];
      b[i]=a[i];
    }

    sort(b,b+n);

    map<ll,ll> mp;
    fr(i,0,n) mp[a[i]]=i;

    fr(i,0,q){
      cin>>x;
      less=count_less(b,n,x);
      cout<<bs(a,n,x,mp[x],less,n-1-less)<<"\n";
    }
  }

  return 0;
}
