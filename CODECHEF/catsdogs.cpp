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

  ll c,d,l,upperLimit,lowerLimit;
  while(t--){
    cin>>c>>d>>l;

    /*
    upperLimit=(c+d)*4;
    lowerLimit=(d+max(0ll,c-d*2ll))*4;

    if(l%4!=0 || l<lowerLimit || l>upperLimit) cout<<"no\n";
    else cout<<"yes\n";
    */

    bool flag=false;

    fr(i,0,2*d+1){
      if(i<=c && (c-i+d)*4==l){
        flag=true;
        break;
      }
    }

    if(!flag || l%4!=0) cout<<"no\n";
    else cout<<"yes\n";
  }

  return 0;
}
