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
#define MAX(a,b,c) max(max(a,b),c)
#define MIN(a,b,c) min(min(a,b),c)

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n,m;
  cin>>n;
  ll a[n];
  fr(i,0,n) cin>>a[i];
  cin>>m;
  ll b[m];
  fr(i,0,m) cin>>b[i];

  sort(a,a+n);
  sort(b,b+m);

  ll ans=0;
  fr(i,0,n){
    fr(j,0,m){
      if(abs(a[i]-b[j])<=1){
        ans++;
        b[j]=INF;
        break;
      }
    }
  }
  cout<<ans;

  return 0;
}
