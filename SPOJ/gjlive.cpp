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

  ll a[10];
  fr(i,0,10) cin>>a[i];

  ll n=0,m=0;
  fr(i,0,10){
    if(n+a[i]<=100) n+=a[i];
    m+=a[i];
    if(m>=100){
      if(100-n==m-100){
        cout<<max(m,n);
        break;
      }
      else{
        if(m-100<100-n) cout<<m;
        else cout<<n;
        break;
      }
    }
  }

  if(m<100) cout<<m;

  return 0;
}
