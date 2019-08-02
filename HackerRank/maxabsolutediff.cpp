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

ll max_val(ll a,ll b){
  return (a>b)?a:b;
}

ll min_val(ll a,ll b){
  return (a<b)?a:b;
}

int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  ll n;
  cin>>n;

  ll a[n];
  ll ia=-INF,ib=-INF;
  ll ma=+INF,mb=+INF;
  fr(i,0,n){
    cin>>a[i];
    ia=max_val(ia,a[i]+i);
    ib=max_val(ib,a[i]-i);
    ma=min_val(ma,a[i]+i);
    mb=min_val(mb,a[i]-i);
  }

  cout<<max_val(ia-ma,ib-mb);

  return 0;
}
