#include<bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 100001

ll h,w;

ll MAX(ll a,ll b,ll c){
  return max(max(a,b),c);
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  ll t;
  cin>>t;

  while(t--){
    cin>>h>>w;

    ll a[h][w+2];
    fr(i,0,h){
      fr(j,0,w+2){
        a[i][j]=0;
      }
    }

    fr(i,0,h){
      fr(j,1,w+1){
        cin>>a[i][j];
      }
    }

    fr(i,0,h) a[i][0]=a[i][w+1]=0;

    for(ll i=h-2;i>=0;i--){
      for(ll j=1;j<=w;j++){
        a[i][j]+=MAX(a[i+1][j-1],a[i+1][j],a[i+1][j+1]);
      }
    }

    ll ans=0;
    fr(j,1,w+1){
      ans=max(ans,a[0][j]);
    }
    cout<<ans<<"\n";
  }

  return 0;
}
