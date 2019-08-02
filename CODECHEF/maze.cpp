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
  ll t;
  cin>>t;

  ll r,c,w,r1,r2,c1,c2;
  while(t--){
    cin>>r>>c>>w;

    fr(i,0,w){
      cin>>r1>>c1>>r2>>c2;
    }

    if(r==1 || c==1){
      if(r==c) cout<<"Chefland is doomed";
      else cout<<!w;
    }

    else{
      
    }

    cout<<"\n";
  }

  return 0;
}
