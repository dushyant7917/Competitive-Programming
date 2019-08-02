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
#define N 100005
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll n;
ll v[N],t[N],prefix_temp[N],left_piles[N]={0},vol_rem[N]={0};

ll bs(ll x,ll i,ll l,ll r){
  ll m,ind=-1;

  while(l<=r){
    m=(l+r)/2;
    if(x<=prefix_temp[m]-prefix_temp[i-1]){
      ind=m;
      r=m-1;
    }
    else l=m+1;
  }

  return ind;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cin>>n;
  fr(i,1,n+1) cin>>v[i];
  fr(i,1,n+1) cin>>t[i];

  prefix_temp[0]=0;
  fr(i,1,n+1) prefix_temp[i]=prefix_temp[i-1]+t[i];

  ll ind;
  fr(i,1,n+1){
    left_piles[i]++;

    ind=bs(v[i],i,i,n);
    if(ind!=-1){
      left_piles[ind]--;
      vol_rem[ind]+=v[i]-(prefix_temp[ind-1]-prefix_temp[i-1]);
    }
  }

  ll cnt=0;
  fr(i,1,n+1){
    cnt+=left_piles[i];
    cout<<cnt*t[i]+vol_rem[i]<<" ";
  }

  return 0;
}
