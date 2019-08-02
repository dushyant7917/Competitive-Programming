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
#define N 1002
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)
#define SZ(s) s.size()
#define MS(x,v) memset(x,v,sizeof(x))
#define fn(x) (abs(x)*abs(x))

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,k1,k2,k;
  cin>>n>>k1>>k2;

  ll a[n],b[n];
  k=k1+k2;

  fr(i,0,n) cin>>a[i];
  fr(i,0,n) cin>>b[i];

  priority_queue<ll> pq;
  fr(i,0,n) pq.push(abs(a[i]-b[i]));

  ll x;
  while(k>0){
    x=pq.top();
    pq.pop();
    if(x>0) x--;
    else x++;
    pq.push(x);
    k--;
  }

  ll ans=0;

  while(SZ(pq)){
    x=pq.top();
    pq.pop();
    ans+=x*x;
  }

  cout<<ans;

  return 0;
}
