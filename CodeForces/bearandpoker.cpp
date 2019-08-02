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

  ll n;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];

  fr(i,0,n){
    while(a[i] && a[i]%2==0) a[i]/=2;
    while(a[i] && a[i]%3==0) a[i]/=3;
  }

  ll x=a[0];
  fr(i,1,n){
    if(a[i]!=x){
      cout<<"No";
      return 0;
    }
  }

  cout<<"Yes";

  return 0;
}
