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

  ll n,k;
  cin>>n>>k;

  ll a[n];
  fr(i,0,n) cin>>a[i];

  sort(a,a+n);

  ll cnt=0;
  fr(i,0,n){
    if(binary_search(a+i,a+n,a[i]+k)) cnt++;
  }

  cout<<cnt;

  return 0;
}
