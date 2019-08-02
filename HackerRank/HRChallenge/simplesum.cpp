#include<bits/stdc++.h>

using namespace std;

typedef unsigned long long ll;
typedef double dbl;
#define fr(x,a,b) for(ll x=a;x<b;x++)
#define rf(x,a,b) for(ll x=a;x>b;x--)
#define pii pair<ll,ll>
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define gmax LLONG_MAX
#define gmin LLONG_MIN
#define INF 2e9
#define N 1000000000000000000
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))

ll F(ll k,ll n){
  ll sum=0;
  for(ll i=1;i<=n;i++){
    sum+=i;
    i*=k;
  }
  return sum;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  fr(k,2,10){
    cout<<k<<":";
    fr(i,1,50){
      cout<<F(k,i)<<" ";
    }
    cout<<"\n";
  }

  return 0;
}
