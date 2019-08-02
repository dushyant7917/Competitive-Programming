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

  ll n,r;
  cin>>n>>r;

  ll a[n],on[n]={0},ans=0;
  fr(i,0,n) cin>>a[i];

  fr(i,0,n){
    if(!a[i]) continue;

    ans++;
    fr(j,max(0ll,i-r+1),min(n-1,i+r-1)+1) on[j]++;
  }

  fr(i,0,n){
    if(on[i]) continue;

    cout<<-1;
    return 0;
  }

  bool flag;

  fr(i,0,n){
    if(!a[i]) continue;

    flag=true;

    fr(j,max(0ll,i-r+1),min(n-1,i+r-1)+1){
      if(on[j]>1) continue;
      flag=false;
    }

    if(!flag) continue;

    ans--;
    fr(j,max(0ll,i-r+1),min(n-1,i+r-1)+1){
      on[j]--;
    }
  }

  cout<<ans;

  return 0;
}